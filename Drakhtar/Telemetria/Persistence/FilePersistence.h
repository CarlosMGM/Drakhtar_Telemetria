#pragma once

#include <list>
#include <string>

#include "IPersistence.h"

class FilePersistence final : public IPersistence {
  std::list<std::string> data_;

 public:
  void send(TrackerEvent* event) override;
  void flush() override;
  ~FilePersistence() = default;
};
