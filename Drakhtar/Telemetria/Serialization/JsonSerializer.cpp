#pragma once
#include "JsonSerializer.h"

#include "Telemetria/TrackerEvents/TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* event) {
  return event->toJson();
}
