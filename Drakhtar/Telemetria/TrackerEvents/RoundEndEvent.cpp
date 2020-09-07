#include "RoundEndEvent.h"

RoundEndEvent::RoundEndEvent() : EndEvent(ROUND_END) {}

std::string RoundEndEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Round End Event",)";
  str += "\n" + EndEvent::toJson() + +",\n";
  str += R"(      "Round#": )" + std::to_string(roundNumber_) + "\n";
  str += "    }";
  return str;
}

void RoundEndEvent::setRoundNumber(uint32_t roundNumber) {
  roundNumber_ = roundNumber;
}
