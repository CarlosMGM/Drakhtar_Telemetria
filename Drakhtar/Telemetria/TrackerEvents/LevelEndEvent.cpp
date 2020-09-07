#include "LevelEndEvent.h"

LevelEndEvent::LevelEndEvent(uint32_t levelNumber, LevelResult result)
    : EndEvent(LEVEL_END), levelNumber_(levelNumber), result_(result) {}

std::string resultToString(LevelResult result) {
  switch (result) {
    case VICTORY:
      return "VICTORY";
    case DEFEAT:
      return "DEFEAT";
    case QUIT:
      return "QUIT";
    case ERROR:
    default:
      return "ERROR";
  }
}

void LevelEndEvent::setRoundsPlayed(uint32_t roundsPlayed) {
  roundsPlayed_ = roundsPlayed;
}

std::string LevelEndEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Level End Event",)";
  str += "\n" + EndEvent::toJson() + +",\n";
  str += R"(      "Level#": )" + std::to_string(levelNumber_) + ",\n";
  str += R"(      "Rounds Played": )" + std::to_string(roundsPlayed_) + ",\n";
  str += R"(      "Result": ")" + resultToString(result_) + "\"\n";
  str += "    }";
  return str;
}
