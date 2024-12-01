#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <string>

struct Config;

class IDatabase {
public:
    virtual ~IDatabase() = default;

    virtual void initialize(const Config& config) = 0;
    virtual void insertDeviceData(int deviceId, int data) = 0;
    virtual void fetchAllDeviceData() = 0;
    // Add other operations as needed (e.g., query specific data, etc.)
};

#endif // DATABASE_INTERFACE_H
