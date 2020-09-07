#include "EndEvent.h"

EndEvent::EndEvent(TrackerEventType type)
    : TrackerEvent(type) {
}

void EndEvent::setDuration(uint32_t duration) {
  duration_.seconds = duration % 60;
  duration /= 60;
  duration_.minutes = duration % 60;
  duration_.hours = duration / 60;
}

std::string EndEvent::toJson() {
  std::string str = TrackerEvent::toJson() + +",\n";

  str += R"(      "Duration": ")";
  if (duration_.hours != 0) {
    if (duration_.hours < 10) str += "0";
    str += std::to_string(duration_.hours) + ":";
  }
  if (duration_.minutes < 10) str += "0";
  str += std::to_string(duration_.minutes) + ":";

  if (duration_.seconds < 10) str += "0";
  str += std::to_string(duration_.seconds) + "\"";
  return str;
}
