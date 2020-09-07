#include "FilePersistence.h"

#include <chrono>
#include <ctime>
#include <fstream>

#include "../Serialization/ISerializer.h"
#include "../Tracker.h"
#include "../TrackerEvents/TrackerEvent.h"

FilePersistence::FilePersistence(uint32_t timer) {
  timer_ = timer;
  std::ofstream file;
  startThread();
}
void FilePersistence::send(TrackerEvent* event) {
  std::lock_guard<std::mutex> lock(eventMutex_);
  events.push(event);
}

void FilePersistence::flush() {
  eventMutex_.lock();
  for (auto size = events.size(); size > 0; --size) {
    auto& event = events.front();
    events.pop();
    eventMutex_.unlock();
    data_.push(serializer_->serialize(event));
    delete event;
    eventMutex_.lock();
  }
  eventMutex_.unlock();

  std::ofstream file;
  if (filename_.empty())
    filename_ = "Telemetry/" + Tracker::getInstance().getIdSession() +
                serializer_->getExtension();

  file.open(filename_, std::ofstream::out | std::ofstream::app);

  while (!data_.empty()) {
    std::string& event = data_.front();
    file << event;
    data_.pop();
  }

  file.close();
}

void FilePersistence::run() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  float previousFlushTime = std::clock();
  previousFlushTime /= CLOCKS_PER_SEC;
  while (Tracker::isRunning()) {
    float currentTime = std::clock();
    currentTime /= CLOCKS_PER_SEC;
    if (currentTime - previousFlushTime >= timer_) {
      flush();
      previousFlushTime = currentTime;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void FilePersistence::startThread() {
  flushThread_ = new std::thread([&]() { run(); });
}

FilePersistence::~FilePersistence() {
  flushThread_->join();
  delete flushThread_;
  flush();
}
