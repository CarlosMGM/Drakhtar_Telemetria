#include "IPersistence.h"

#include "../Serialization/ISerializer.h"
#include "Telemetria/TrackerEvents/TrackerEvent.h"

void IPersistence::setSerializer(ISerializer* serializer) {
  serializer_ = serializer;
}

IPersistence::~IPersistence() {
  delete serializer_;

  while (!events.empty()) {
    delete events.front();
    events.pop();
  }
}
