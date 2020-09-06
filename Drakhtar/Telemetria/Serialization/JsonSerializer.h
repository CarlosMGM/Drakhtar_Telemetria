#pragma once
#include "ISerializer.h"

class JsonSerializer : public ISerializer {
 public:
  std::string serialize(TrackerEvent* event) override;
};
