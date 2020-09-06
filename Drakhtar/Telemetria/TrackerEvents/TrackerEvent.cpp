#pragma once
#include "TrackerEvent.h"

#include "Telemetria/Tracker.h"

TrackerEvent::TrackerEvent(TrackerEventType type)
    : eventType_(type), idSession_(Tracker::getInstance().getIdSession()) {
  std::time(&timestamp_);
}
