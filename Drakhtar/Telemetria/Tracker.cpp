#include "Tracker.h"

#include <combaseapi.h>

#include <cstdio>
#include <iostream>

#include "Persistence/IPersistence.h"
#include "TrackerAssets/PlayTracker.h"
#include "TrackerEvents/SessionEndEvent.h"
#include "TrackerEvents/SessionStartEvent.h"
#include "third_party/TinySHA1.hpp"

Tracker* Tracker::instance_ = nullptr;
bool Tracker::running = false;

std::string Tracker::getIdSession() { return idSession_; }

void Tracker::init() {
  std::time(&timestamp_);

  idSession_ = getSpecialId(timestamp_);
  running = true;
  trackEvent(new SessionStartEvent());
}

void Tracker::activateTracker(assets tracker) {
  switch (tracker) {
    case PLAY_TRACKER:
      activeTrackers_.push_back(new PlayTracker());
      break;
    default:
      break;
  }
}

void Tracker::end() {
  std::time_t endTimeStamp;
  std::time(&endTimeStamp);
  uint32_t duration = std::difftime(endTimeStamp, timestamp_);

  trackEvent(new SessionEndEvent(duration));

  running = false;
  delete persistence_;
  while (!activeTrackers_.empty()) {
    delete activeTrackers_.back();
    activeTrackers_.pop_back();
  }
  delete instance_;
}

Tracker& Tracker::getInstance() {
  if (instance_ == nullptr) instance_ = new Tracker();
  return *instance_;
}

void Tracker::setPersistence(IPersistence* persistence) {
  persistence_ = persistence;
}

void Tracker::trackEvent(TrackerEvent* event) {
  bool accepted = false;
  for (auto it = activeTrackers_.begin();
    it != activeTrackers_.end(); ++it)
    accepted = (*it)->accept(event) || accepted;

  if (accepted) persistence_->send(event);
}

std::string Tracker::getSpecialId(std::time_t& timestamp) {
  try {
    GUID gidReference;
    HRESULT hCreateGuid = CoCreateGuid(&gidReference);
    if (hCreateGuid != S_OK)
      throw std::exception(
          "TrackerError: No se ha podido crear IdSession Correctamente");
    sha1::SHA1 s;
    uint64_t val[4];
    val[0] = timestamp + gidReference.Data1;
    val[1] = timestamp + gidReference.Data2;
    val[2] = timestamp + gidReference.Data3;

    uint64_t aux = 0;
    for (int i = 0; i < 8; ++i) {
      aux += (gidReference.Data4[i] << i * sizeof(char));
    }
    val[3] = timestamp + aux;

    s.processBytes(val, sizeof(int64_t) * 4);

    uint32_t digest[5];

    s.getDigest(digest);

    char tmp[48];

    snprintf(tmp, 45, "%08X-%08X-%08X-%08X-%08X", digest[0], digest[1],
             digest[2], digest[3], digest[4]);

    return std::string(tmp);
  } catch (std::exception& e) {
    std::cerr << e.what();
    return "MISSING";
  }
}
