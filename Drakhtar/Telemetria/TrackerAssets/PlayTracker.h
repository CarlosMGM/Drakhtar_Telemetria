#pragma once
#include "ITrackerAsset.h"

class PlayTracker : public ITrackerAsset {
 public:
  PlayTracker() = default;
  ~PlayTracker() = default;

  bool accept(TrackerEvent* event) override;
};
