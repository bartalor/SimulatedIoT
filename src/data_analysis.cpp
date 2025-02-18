#include "data_analysis.h"
#include "database_interface.h"
#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

static mongocxx::client client{mongocxx::uri{}};

void analyzeData(IDatabase& db, const Config& config) {
    auto dataEntries = db.fetchAllDeviceData();

    int total = 0;
    int count = 0;
    for (const auto& entry : dataEntries) {
        total += entry.data;
        count++;
    }

    if (count > 0) {
        std::cout << "Average device data: " << (total / count) << std::endl;
    } else {
        std::cout << "No data available for analysis." << std::endl;
    }
}

void analyzeDataByDevice(IDatabase& db, int deviceId) {
    auto dataEntries = db.fetchDataByDevice(deviceId);

    int total = 0;
    int count = 0;

    for (const auto& entry : dataEntries) {
        total += entry.data;
        ++count;
    }

    if (count > 0) {
        std::cout << "Average data for device " << deviceId << ": " << (total / count) << std::endl;
    } else {
        std::cout << "No data available for device " << deviceId << "." << std::endl;
    }
}

void detectAnomalies(IDatabase& db, int threshold) {
    auto dataEntries = db.fetchAllDeviceData();

    for (const auto& entry : dataEntries) {
        if (entry.data > threshold) {
            std::cout << "Anomaly detected! Device " << entry.deviceId
                      << " sent unusually high data: " << entry.data << std::endl;
        }
    }
}

