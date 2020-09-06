#pragma once
#include "Telemetria/TrackerEvents/TrackerEvent.h"

class ITrackerAsset {
 public:
  virtual bool accept(TrackerEvent* event) = 0;
};
