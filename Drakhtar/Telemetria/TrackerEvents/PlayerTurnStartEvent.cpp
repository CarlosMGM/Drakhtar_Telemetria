#include "PlayerTurnStartEvent.h"

PlayerTurnStartEvent::PlayerTurnStartEvent()
    : TrackerEvent(PLAYER_TURN_START) {}

std::string PlayerTurnStartEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Player Turn Start Event",)";
  str += "\n" + TrackerEvent::toJson() + +"\n";
  str += "    }";
  return str;
}
