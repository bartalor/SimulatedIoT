#include <iostream>
#include "config_handler.h"
#include "database_interface.h"
#include "database_factory.h"
#include "data_analysis_interface.h"
#include "data_analysis_factory.h"
#include "device_simulator.h"
#include "simulation_manager.h"

int main() {
    auto config = loadConfig("config.json");

    // Create database instance
    std::unique_ptr<IDatabase> db(createDatabase(config));
    db->initialize(config);

    // Start the simulation
    SimulationManager simulation(config, *db);
    simulation.start();

    // Create data analysis instance
    std::unique_ptr<IDataAnalysis> dataAnalysis(createDataAnalysis(config, *db));

    // Perform data analysis
    dataAnalysis->analyzeData();
    dataAnalysis->analyzeDataByDevice(0);
    dataAnalysis->detectAnomalies();

    return 0;
}
