#ifndef DATABASE_FACTORY_H
#define DATABASE_FACTORY_H

#include "config_handler.h"
#include "database_interface.h"
#include "mongodb_handler.h"

inline IDatabase* createDatabase(const Config& config) {
    if (config.db_type == "MongoDB") {
        return new MongoDBHandler();
    } else if (config.db_type == "SQLite") {
        // Placeholder for future SQLite implementation
        throw std::runtime_error("SQLite is not yet implemented.");
    } else {
        throw std::runtime_error("Unsupported database type: " + config.db_type);
    }
}

#endif // DATABASE_FACTORY_H
