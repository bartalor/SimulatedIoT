#ifndef DATA_ANALYSIS_FACTORY_H
#define DATA_ANALYSIS_FACTORY_H

#include "data_analysis_interface.h"
#include "config_handler.h"
#include "database_interface.h"
#include "mongodb_data_analysis.h"
// #include "sqlite_data_analysis.h" // Future implementation

inline IDataAnalysis* createDataAnalysis(const Config& config, IDatabase& db) {
    if (config.db_type == "MongoDB") {
        return new MongoDBDataAnalysis(config, db);
    } else if (config.db_type == "SQLite") {
        // return new SQLiteDataAnalysis(config, db); // When implemented
        throw std::runtime_error("SQLiteDataAnalysis is not implemented yet.");
    } else {
        throw std::runtime_error("Unsupported database type: " + config.db_type);
    }
}

#endif // DATA_ANALYSIS_FACTORY_H
