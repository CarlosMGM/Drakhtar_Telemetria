#pragma once
#include "EndEvent.h"

enum LevelResult { VICTORY, DEFEAT, QUIT, ERROR };

class LevelEndEvent : public EndEvent {
  uint32_t levelNumber_;
  uint32_t roundsPlayed_;
  LevelResult result_;

 public:
  LevelEndEvent(uint32_t levelNumber, LevelResult result);
  ~LevelEndEvent() override = default;
  void setRoundsPlayed(uint32_t roundsPlayed);
  std::string toJson() override;
};
