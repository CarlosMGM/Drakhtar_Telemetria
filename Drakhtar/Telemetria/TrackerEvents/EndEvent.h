#pragma once
#include "TrackerEvent.h"

class EndEvent : public TrackerEvent {
 protected:
  EndEvent(TrackerEventType type);
  struct Duration {
    uint32_t hours;
    uint8_t minutes;
    uint8_t seconds;
  };

  Duration duration_;

 public:
  void setDuration(uint32_t duration);
  ~EndEvent() override = default;
  std::string toJson() override;
};
