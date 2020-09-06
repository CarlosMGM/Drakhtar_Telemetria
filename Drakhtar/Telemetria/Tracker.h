#pragma once
#include <ctime>
#include <list>
#include <string>

#include "TrackerAssets/ITrackerAsset.h"

enum assets { PLAY_TRACKER };

class Tracker {
  static Tracker* instance_ = nullptr;
  Tracker() = default;

  std::string idSession_;

  std::string getSpecialId(std::time_t& timestamp);

  // Persistence Object
  std::list<ITrackerAsset*> activeTrackers;

 public:
  void init();
  void activateTracker(assets tracker);
  void end();
  static const Tracker& getInstance();
  void trackEvent();
  const std::string& getIdSession() const { return idSession_; };
};
