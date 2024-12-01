#include <iostream>
#include "config_handler.h"
#include "device_simulator.h"
#include "database_handler.h"
#include "simulation_manager.h"
#include "data_analysis.h"

int main() {
    auto config = loadConfig("config.json");

    initDatabaseClient();
    std::cout << "Starting IoT Simulation..." << std::endl;

    SimulationManager simulation(config);
    simulation.start();

    std::cout << "Performing Data Analysis..." << std::endl;
    analyzeData(config);
    analyzeDataByDevice(config, 0);
    detectAnomalies(config);

    return 0;
}
