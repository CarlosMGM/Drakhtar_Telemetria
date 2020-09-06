#pragma once
#include <ctime>
#include <mutex>
#include <queue>
#include <thread>

class TrackerEvent;
class ISerializer;

class IPersistence {
 protected:
  ISerializer* serializer_ = nullptr;
  std::queue<TrackerEvent*> events{};
  std::queue<std::string> data_{};
  IPersistence() = default;

 public:
  void setSerializer(ISerializer* serializer);

  virtual void send(TrackerEvent* event) = 0;
  virtual void flush() = 0;
  virtual ~IPersistence();
};
