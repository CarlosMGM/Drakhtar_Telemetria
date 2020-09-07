#pragma once
#include "EndEvent.h"

class RoundEndEvent : public EndEvent {
  uint32_t roundNumber_;

 public:
  RoundEndEvent();
  ~RoundEndEvent() override = default;
  void setRoundNumber(uint32_t roundNumber);
  std::string toJson() override;
};
