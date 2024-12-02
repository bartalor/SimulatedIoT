#ifndef MONGODB_HANDLER_H
#define MONGODB_HANDLER_H

#include "database_interface.h"
#include "config_handler.h"
#include <mongocxx/database.hpp>
#include <mongocxx/pool.hpp>

class MongoDBHandler : public IDatabase {
public:
    void initialize(const Config& config) override;
    void insertDeviceData(int deviceId, int data) override;
    std::vector<DataEntry> fetchAllDeviceData() override;
    std::vector<DataEntry> fetchDataByDevice(int deviceId) override;

private:
    mongocxx::database db;
    std::string collection_name;
    static mongocxx::pool pool;
};

#endif // MONGODB_HANDLER_H
