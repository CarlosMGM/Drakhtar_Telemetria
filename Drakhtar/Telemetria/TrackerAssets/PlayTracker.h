#pragma once
#include <cstdint>

#include "ITrackerAsset.h"

class PlayTracker : public ITrackerAsset {
  uint32_t roundCount = 0;
  time_t startRoundTime = 0;
  time_t startPlayerTurnTime = 0;
 public:
  PlayTracker() = default;
  ~PlayTracker() = default;

  bool accept(TrackerEvent* event) override;
};
