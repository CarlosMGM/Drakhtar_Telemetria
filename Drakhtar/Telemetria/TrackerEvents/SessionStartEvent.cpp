#include "SessionStartEvent.h"

SessionStartEvent::SessionStartEvent() : TrackerEvent(SESSION_START) {}

std::string SessionStartEvent::toJson() {
  std::string str = "{\n";
  str += R"(  "Telemetry": [)";
  str += "\n    {\n";
  str += R"(      "Event Type": "Session Start Event",)";
  str += "\n" + TrackerEvent::toJson() + "\n";
  str += "    }";
  return str;
};
