#include "SessionEndEvent.h"

SessionEndEvent::SessionEndEvent(uint32_t duration)
    : EndEvent(SESSION_END) {
  setDuration(duration);
}

std::string SessionEndEvent::toJson() { 
std::string str = ",\n\n";
  str += R"(  "Session End Event": {)";
  str += "\n" + EndEvent::toJson() + +"\n";
  str += "  }\n}\n\n\n";
  return str;
}

