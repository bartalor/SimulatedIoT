#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <mongocxx/pool.hpp>
#include <mongocxx/client.hpp>
#include <string>

class DatabaseManager {
public:
    static mongocxx::database getDatabase(const std::string& db_name);

private:
    static mongocxx::pool pool; // Connection pool
};

void initDatabaseClient();
void insertDeviceData(int deviceId, int data);
void fetchAllDeviceData();

#endif
