#ifndef DEVICE_SIMULATOR_H
#define DEVICE_SIMULATOR_H

#include "config_handler.h"
#include "database_interface.h"

void simulateDevice(const Config& config, IDatabase& db, int deviceId);

#endif // DEVICE_SIMULATOR_H
