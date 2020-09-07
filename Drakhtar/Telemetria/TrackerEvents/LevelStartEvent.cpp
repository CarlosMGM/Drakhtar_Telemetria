#include "LevelStartEvent.h"

LevelStartEvent::LevelStartEvent(uint32_t levelNumber)
    : TrackerEvent(LEVEL_START), levelNumber_(levelNumber) {}

std::string LevelStartEvent::toJson() {
  std::string str = ",\n\n";
  str += R"(  "Level Start Event": {)";
  str += "\n" + TrackerEvent::toJson() + +",\n";
  str += R"(    "Level #": )" + std::to_string(levelNumber_) + "\n";
  str += "  }";
  return str;
}
