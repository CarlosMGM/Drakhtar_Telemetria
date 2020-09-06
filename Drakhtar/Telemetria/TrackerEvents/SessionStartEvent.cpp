#pragma once

#include "SessionStartEvent.h"

SessionStartEvent::SessionStartEvent() : TrackerEvent(SESSION_START) {}

std::string SessionStartEvent::toJson() { return std::string(); };
