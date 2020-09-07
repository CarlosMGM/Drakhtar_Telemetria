#pragma once
#include "EndEvent.h"

class PlayerTurnEndEvent : public EndEvent {
 public:
  PlayerTurnEndEvent();
  ~PlayerTurnEndEvent() override = default;
  std::string toJson() override;
};
