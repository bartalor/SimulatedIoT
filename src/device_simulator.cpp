#include "device_simulator.h"
#include "database_handler.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

void simulateDevice(int deviceId) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(20, 100);

    for (int i = 0; i < 5; ++i) {
        int data = dist(gen);
        std::cout << "Device " << deviceId << " generated data: " << data << std::endl;

        // Store data in the database
        insertDeviceData(deviceId, data);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
