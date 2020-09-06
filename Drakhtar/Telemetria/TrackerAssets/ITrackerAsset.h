#pragma once
class TrackerEvent;

class ITrackerAsset {
 public:
  virtual bool accept(TrackerEvent* event) = 0;
  ITrackerAsset() = default;
  virtual ~ITrackerAsset() = default;
};
