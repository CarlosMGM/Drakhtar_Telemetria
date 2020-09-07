#pragma once
#include "TrackerEvent.h"

class PlayerTurnStartEvent : public TrackerEvent {
 public:
  PlayerTurnStartEvent();
  ~PlayerTurnStartEvent() override = default;
  std::string toJson() override;
};
