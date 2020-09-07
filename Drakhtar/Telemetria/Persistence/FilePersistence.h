#pragma once

#include <string>

#include "IPersistence.h"

class FilePersistence final : public IPersistence {
  std::mutex eventMutex_;
  uint32_t timer_ = 60;
  std::thread* flushThread_;
  std::string filename_ = "";

 public:
  FilePersistence(uint32_t timer);
  void send(TrackerEvent* event) override;
  void flush() override;
  void run();
  void startThread();
  ~FilePersistence();
};
