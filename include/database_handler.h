#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <mongocxx/pool.hpp>
#include <mongocxx/client.hpp>
#include <string>
#include "config_handler.h"

class DatabaseManager {
public:
    static mongocxx::database getDatabase(const std::string& db_name);

private:
    static mongocxx::pool pool; // Connection pool
};

// Functions for interacting with the database
void initDatabaseClient();
void insertDeviceData(const Config& config, int deviceId, int data);
void fetchAllDeviceData(const Config& config);

#endif // DATABASE_HANDLER_H
