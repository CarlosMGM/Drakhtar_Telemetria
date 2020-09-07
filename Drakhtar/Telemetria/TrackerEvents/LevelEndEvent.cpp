#include "LevelEndEvent.h"

LevelEndEvent::LevelEndEvent(uint32_t levelNumber,
                             LevelResult result)
    : EndEvent(LEVEL_END),
      levelNumber_(levelNumber),
      result_(result) {}

std::string resultToString(LevelResult result) {
  switch (result) {
    case VICTORY:
      return "VICTORY";
    case DEFEAT:
      return "DEFEAT";
    case QUIT:
      return "QUIT";
    case ERROR:
      return "ERROR";
  }
}

std::string LevelEndEvent::toJson() { 
  std::string str = ",\n\n";
  str += R"(  "Level End Event": {)";
  str += "\n" + TrackerEvent::toJson() + +",\n";
  str += R"(    "Level #": )" + std::to_string(levelNumber_) + ",\n";
  str += R"(    "Result": ")"  + resultToString(result_) + "\"\n";
  str += "  }";
  return str;

}
