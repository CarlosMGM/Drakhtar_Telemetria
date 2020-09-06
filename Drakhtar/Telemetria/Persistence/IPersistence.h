#pragma once

class TrackerEvent;
class ISerializer;

class IPersistence {
  ISerializer* serializer_ = nullptr;

 protected:
  IPersistence() = default;

 public:
  void setSerializer(ISerializer* serializer);

  virtual void send(TrackerEvent* event) = 0;
  virtual void flush() = 0;
  virtual ~IPersistence();
};
