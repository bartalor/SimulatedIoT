#include "simulation_manager.h"
#include "device_simulator.h"

SimulationManager::SimulationManager(const Config& config) : config(config) {}

void SimulationManager::start() {
    for (int i = 0; i < config.num_threads; ++i) {
        // Use a lambda to pass additional arguments to simulateDevice
        threads.emplace_back([this, i]() {
            simulateDevice(config, i);
        });
    }
    for (auto& thread : threads) {
        thread.join();
    }
}
