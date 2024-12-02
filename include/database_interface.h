#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <vector>
#include "config_handler.h"

struct DataEntry {
    int deviceId;
    int data;
    // Add other fields if necessary
};

class IDatabase {
public:
    virtual ~IDatabase() = default;

    virtual void initialize(const Config& config) = 0;
    virtual void insertDeviceData(int deviceId, int data) = 0;
    virtual std::vector<DataEntry> fetchAllDeviceData() = 0;
    virtual std::vector<DataEntry> fetchDataByDevice(int deviceId) = 0;
};

#endif // DATABASE_INTERFACE_H
