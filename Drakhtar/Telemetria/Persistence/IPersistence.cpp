#pragma once
#include "IPersistence.h"

#include "../Serialization/ISerializer.h"

void IPersistence::setSerializer(ISerializer* serializer) {
  serializer_ = serializer;
}

IPersistence::~IPersistence() { delete serializer_; }
