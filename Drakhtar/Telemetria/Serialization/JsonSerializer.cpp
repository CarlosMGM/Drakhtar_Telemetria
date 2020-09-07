#include "JsonSerializer.h"

#include "Telemetria/TrackerEvents/TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* event) noexcept {
  return event->toJson();
}
