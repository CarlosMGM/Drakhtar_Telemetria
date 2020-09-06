#pragma once
#include <string>

class TrackerEvent;

class ISerializer {
 public:
  virtual std::string serialize(TrackerEvent* event) noexcept = 0;
  ISerializer() = default;
  virtual ~ISerializer() = default;
};
