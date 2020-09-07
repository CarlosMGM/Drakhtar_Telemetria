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

void TrackerConfiguration();

#endif
