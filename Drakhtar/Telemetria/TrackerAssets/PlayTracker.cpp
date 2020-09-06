#pragma once
#include "PlayTracker.h"

inline bool PlayTracker::accept(TrackerEvent* event) {
  switch (event->eventType_) {
    case SESSION_START:
    case SESSION_END:
    case LEVEL_START:
    case LEVEL_END:
    case ROUND_START:
    case ROUND_END:
    case PLAYER_TURN_START:
    case PLAYER_TURN_TIME:
      return true;
    default:
      return false;
  }
}
