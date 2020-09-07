#include "SessionEndEvent.h"

SessionEndEvent::SessionEndEvent(uint32_t duration) : EndEvent(SESSION_END) {
  setDuration(duration);
}

std::string SessionEndEvent::toJson() {
  std::string str = ",\n";
  str += "    {\n";
  str += R"(      "Event Type": "Session End Event",)";
  str += "\n" + EndEvent::toJson() + +"\n";
  str += "    }\n";
  str += "  ]\n";
  str += "}\n\n";
  return str;
}
