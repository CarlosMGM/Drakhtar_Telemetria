#include "PlayTracker.h"

#include "Telemetria/TrackerEvents/LevelEndEvent.h"
#include "Telemetria/TrackerEvents/RoundEndEvent.h"
#include "Telemetria/TrackerEvents/RoundStartEvent.h"
#include "Telemetria/TrackerEvents/TrackerEvent.h"

bool PlayTracker::accept(TrackerEvent* event) {
  time_t endTime;
  switch (event->eventType_) {
    case SESSION_START:
    case SESSION_END:
      return true;
    case PLAYER_TURN_START:
      std::time(&startPlayerTurnTime_);
      return false;
    case PLAYER_TURN_END:
      std::time(&endTime);
      reinterpret_cast<EndEvent*>(event)->setDuration(
          std::difftime(endTime, startPlayerTurnTime_));
      return true;

    case ROUND_START:
      std::time(&startRoundTime_);
      reinterpret_cast<RoundStartEvent*>(event)->setRoundNumber(1 +
                                                                roundCount_);
      return false;

    case ROUND_END:
      std::time(&endTime);
      reinterpret_cast<EndEvent*>(event)->setDuration(
          std::difftime(endTime, startRoundTime_));
      reinterpret_cast<RoundEndEvent*>(event)->setRoundNumber(++roundCount_);
      return true;

    case LEVEL_START:
      std::time(&startLevelTime_);
      roundCount_ = 0;
      return true;

    case LEVEL_END:
      std::time(&endTime);
      reinterpret_cast<EndEvent*>(event)->setDuration(
          std::difftime(endTime, startLevelTime_));
      reinterpret_cast<LevelEndEvent*>(event)->setRoundsPlayed(roundCount_);
      return true;

    default:
      return false;
  }
}
