#pragma once

#include <ctime>
#include <string>

enum TrackerEventType {
  SESSION_START,
  SESSION_END,
  LEVEL_START,
  LEVEL_END,
  ROUND_START,
  ROUND_END,
  PLAYER_TURN_START,
  PLAYER_TURN_TIME
};

class TrackerEvent {
  time_t timestamp_;

 protected:
  TrackerEvent(TrackerEventType type);

 public:
  const TrackerEventType eventType_;
  const uint32_t idSession_;

  time_t getTimeStamp() const { return timestamp_; };

  virtual std::string toJson() = 0;
};
