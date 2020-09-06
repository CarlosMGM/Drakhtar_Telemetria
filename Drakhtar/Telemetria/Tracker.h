#pragma once
#include <ctime>
#include <list>
#include <string>

class ITrackerAsset;
class TrackerEvent;
class IPersistence;

enum assets { PLAY_TRACKER };

class Tracker {
  static Tracker* instance_ = nullptr;
  Tracker() = default;

  std::string idSession_;

  std::string getSpecialId(std::time_t& timestamp);

  IPersistence* persistence_;
  std::list<ITrackerAsset*> activeTrackers_;

 public:
  void init();
  void activateTracker(assets tracker);
  void end();
  static const Tracker& getInstance();
  void trackEvent(TrackerEvent* event);
  const std::string& getIdSession() const { return idSession_; };
};
