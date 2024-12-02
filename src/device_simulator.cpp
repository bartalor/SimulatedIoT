#include "device_simulator.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

void simulateDevice(const Config& config, IDatabase& db, int deviceId) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(config.min_data, config.max_data);

    for (int i = 0; i < 5; ++i) {
        int data = dist(gen);
        std::cout << "Device " << deviceId << " generated data: " << data << std::endl;

        // Store data in the database
        db.insertDeviceData(deviceId, data);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
