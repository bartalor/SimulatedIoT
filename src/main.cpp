#include <iostream>
#include <thread>
#include <vector>
#include "device_simulator.h"
#include "database_handler.h"
#include "data_analysis.h"

int main() {
    initDatabaseClient();
    std::cout << "Starting IoT Device Simulation..." << std::endl;

    std::vector<std::thread> deviceThreads;
    for (int i = 0; i < 5; ++i) {
        deviceThreads.emplace_back(simulateDevice, i);
    }

    for (auto& thread : deviceThreads) {
        thread.join();
    }

    std::cout << "All device simulations completed." << std::endl;

    analyzeData();             // General analysis for all devices
    analyzeDataByDevice(2);    // Analyze data for device with ID 2
    detectAnomalies();         // Check for anomalies
    return 0;
}
