#pragma once
#include "EndEvent.h"

enum LevelResult {
  VICTORY,
  DEFEAT,
  QUIT,
  ERROR
};

class LevelEndEvent : public EndEvent {
  uint32_t levelNumber_;
  LevelResult result_;

 public:
 LevelEndEvent(uint32_t duration, uint32_t levelNumber, LevelResult result);
  ~LevelEndEvent() override = default;
  std::string toJson() override;
};