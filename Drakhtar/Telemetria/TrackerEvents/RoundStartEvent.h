#pragma once
#include "TrackerEvent.h"

class RoundStartEvent : TrackerEvent {
  uint32_t roundNumber_;

 public:
  RoundStartEvent();
  void setRoundNumber(uint32_t roundNumber);
  ~RoundStartEvent() override = default;
  std::string toJson() override;
};
