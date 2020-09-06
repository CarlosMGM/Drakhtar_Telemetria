#pragma once
#include <ctime>
#include <list>
#include <string>

class ITrackerAsset;
class TrackerEvent;
class IPersistence;

enum assets { PLAY_TRACKER };

class Tracker {
  static Tracker* instance_;
  static bool running;
  Tracker() = default;
  ~Tracker() = default;

  std::string idSession_;

  std::string getSpecialId(std::time_t& timestamp);

  IPersistence* persistence_;
  std::list<ITrackerAsset*> activeTrackers_;

 public:
  static Tracker& getInstance();
  static bool isRunning() { return running; }

  void init();
  void end();

  void activateTracker(assets tracker);
  void setPersistence(IPersistence* persistence);

  void trackEvent(TrackerEvent* event);
  const std::string& getIdSession() const { return idSession_; };
};
