#pragma once
#include "ITrackerAsset.h"

class PlayTracker : public ITrackerAsset {
  bool accept(TrackerEvent* event) override;
};
