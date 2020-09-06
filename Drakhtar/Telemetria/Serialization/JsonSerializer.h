#pragma once
#include "ISerializer.h"

class JsonSerializer : public ISerializer {
 public:
  std::string serialize(TrackerEvent* event) noexcept override;
  std::string getExtension() override { return ".json"; };
  JsonSerializer() = default;
  ~JsonSerializer() = default;
};
