#include "Configuration.h"

#ifdef TELEMETRY

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