#ifndef SIMULATION_MANAGER_H
#define SIMULATION_MANAGER_H

#include "config_handler.h"
#include "database_interface.h"
#include <thread>
#include <vector>

class SimulationManager {
public:
    SimulationManager(const Config& config, IDatabase& db);
    void start();

private:
    const Config& config;
    IDatabase& db;
    std::vector<std::thread> threads;
};

#endif // SIMULATION_MANAGER_H
