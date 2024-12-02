#include "mongodb_data_analysis.h"
#include <iostream>
#include <vector>

MongoDBDataAnalysis::MongoDBDataAnalysis(const Config& config, IDatabase& db)
    : config(config), db(db) {}

void MongoDBDataAnalysis::analyzeData() {
    auto dataEntries = db.fetchAllDeviceData();

    int total = 0;
    int count = 0;

    for (const auto& entry : dataEntries) {
        total += entry.data;
        ++count;
    }

    if (count > 0) {
        std::cout << "Average device data: " << (total / count) << std::endl;
    } else {
        std::cout << "No data available for analysis." << std::endl;
    }
}

void MongoDBDataAnalysis::analyzeDataByDevice(int deviceId) {
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

void MongoDBDataAnalysis::detectAnomalies() {
    auto dataEntries = db.fetchAllDeviceData();

    for (const auto& entry : dataEntries) {
        if (entry.data > 90) { // Arbitrary threshold for anomaly
            std::cout << "Anomaly detected! Device " << entry.deviceId
                      << " sent unusually high data: " << entry.data << std::endl;
        }
    }
}
