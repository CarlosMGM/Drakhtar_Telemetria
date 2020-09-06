#pragma once

class TrackerEvent;

class IPersistence {
 public:
  virtual void send(TrackerEvent* event) = 0;
  virtual void flush() = 0;
};
