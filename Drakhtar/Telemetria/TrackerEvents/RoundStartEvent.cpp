#include "RoundStartEvent.h"

RoundStartEvent::RoundStartEvent() : TrackerEvent(ROUND_START) {}

void RoundStartEvent::setRoundNumber(uint32_t roundNumber) {
  roundNumber_ = roundNumber;
}

std::string RoundStartEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Round Start Event",)";
  str += "\n" + TrackerEvent::toJson() + +",\n";
  str += R"(      "Round#": )" + std::to_string(roundNumber_) + "\n";
  str += "    }";
  return str;
}
