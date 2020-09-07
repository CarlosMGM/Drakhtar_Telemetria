#pragma once
#include "TrackerEvent.h"
uint32_t hello;

class LevelStartEvent : public TrackerEvent {
  uint32_t levelNumber_;

 public:
  LevelStartEvent(uint32_t levelNumber);
  ~LevelStartEvent() override = default;
  std::string toJson() override;
};