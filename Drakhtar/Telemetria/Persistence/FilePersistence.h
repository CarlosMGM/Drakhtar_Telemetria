#pragma once

#include "IPersistence.h"

class FilePersistence : public IPersistence {
  void send(TrackerEvent* event) override;
  void flush() override;
};
