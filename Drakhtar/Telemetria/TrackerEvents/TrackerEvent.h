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
  PLAYER_TURN_END
};

class TrackerEvent {
  time_t timestamp_;

 protected:
  TrackerEvent(TrackerEventType type);

 public:
  virtual ~TrackerEvent() = default;

  const TrackerEventType eventType_;
  const std::string idSession_;

  time_t getTimeStamp() const { return timestamp_; };

  virtual std::string toJson();
};
