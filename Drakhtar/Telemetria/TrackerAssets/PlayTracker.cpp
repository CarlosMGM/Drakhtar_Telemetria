#include "PlayTracker.h"

#include "Telemetria/TrackerEvents/TrackerEvent.h"
#include "Telemetria/TrackerEvents/EndEvent.h"

bool PlayTracker::accept(TrackerEvent* event) {
  switch (event->eventType_) {
    case SESSION_START:
    case SESSION_END:
    case ROUND_START:
    case ROUND_END:
    case PLAYER_TURN_START:
    case PLAYER_TURN_TIME:
      return true;

    case LEVEL_START:
      std::time(&startLevelTime_);
      return true;

    case LEVEL_END:
      time_t endtime;
      std::time(&endtime);
      reinterpret_cast<EndEvent*>(event)->setDuration(std::difftime(endtime, startLevelTime_));
      return true;

    default:
      return false;
  }
}
