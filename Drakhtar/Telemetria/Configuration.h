#pragma once

#define TELEMETRY
#define FILE_PERSISTENCE
#define JSON_SERIALIZER

#ifdef TELEMETRY
#include "Tracker.h"

#ifdef FILE_PERSISTENCE
#include "Persistence/FilePersistence.h"
#else
#endif

#ifdef JSON_SERIALIZER
#include "Serialization/JsonSerializer.h"
#else
#endif

void TrackerConfiguration() {
  ISerializer* serializer = nullptr;
  IPersistence* persistence = nullptr;
#ifdef FILE_PERSISTENCE
  persistence = new FilePersistence(10);
#else
#endif

#ifdef JSON_SERIALIZER
  serializer = new JsonSerializer();
#else
#endif

  Tracker::getInstance().activateTracker(PLAY_TRACKER);

  persistence->setSerializer(serializer);

  Tracker::getInstance().setPersistence(persistence);
}

#endif
