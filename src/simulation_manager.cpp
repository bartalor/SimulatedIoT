#include "simulation_manager.h"
#include "device_simulator.h"

SimulationManager::SimulationManager(const Config& config, IDatabase& db)
    : config(config), db(db) {}

void SimulationManager::start() {
    for (int i = 0; i < config.num_threads; ++i) {
        threads.emplace_back([this, i]() {
            simulateDevice(this->config, this->db, i); // Pass both config and db
        });
    }
    for (auto& thread : threads) {
        thread.join();
    }
}
