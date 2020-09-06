#include "Tracker.h"

#include <combaseapi.h>

#include <cstdio>

#include "TrackerAssets/PlayTracker.h"
#include "third_party/TinySHA1.hpp"

void Tracker::init() {
  std::time_t timestamp;
  std::time(&timestamp);

  idSession_ = getSpecialId(timestamp);
}

void Tracker::activateTracker(assets tracker) {
  switch (tracker) {
    case PLAY_TRACKER:
      activeTrackers.push_back(new PlayTracker());
      break;
    default:
      break;
  }
}

void Tracker::end() {
  while (!activeTrackers.empty()) {
    delete activeTrackers.back();
    activeTrackers.pop_back();
  }
}

const Tracker& Tracker::getInstance() {
  if (instance_ == nullptr) instance_ = new Tracker();
  return *instance_;
}

void Tracker::trackEvent() {}

std::string Tracker::getSpecialId(std::time_t& timestamp) {
  GUID gidReference;
  HRESULT hCreateGuid = CoCreateGuid(&gidReference);
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

  snprintf(tmp, 45, "%08X-%08X-%08X-%08X-%08X", digest[0], digest[1], digest[2],
           digest[3], digest[4]);

  return std::string(tmp);
}
