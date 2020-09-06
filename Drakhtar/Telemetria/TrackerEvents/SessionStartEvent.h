#pragma once
#include "TrackerEvent.h"

class SessionStartEvent : public TrackerEvent {
 public:
  SessionStartEvent();
  ~SessionStartEvent() = default;
  std::string toJson() override;
};
