#include "database_handler.h"
#include <mongocxx/uri.hpp>
#include <mongocxx/pool.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <iostream>

// Define the connection pool
mongocxx::pool DatabaseManager::pool{mongocxx::uri{}};

mongocxx::database DatabaseManager::getDatabase(const std::string& db_name) {
    auto client = pool.acquire(); // Get a client from the pool
    return (*client)[db_name];    // Return the database instance
}

void initDatabaseClient() {
    std::cout << "Connected to MongoDB using connection pool successfully." << std::endl;
}

void insertDeviceData(const Config& config, int deviceId, int data) {
    auto db = DatabaseManager::getDatabase(config.db_name);
    auto collection = db[config.collection_name];

    bsoncxx::builder::stream::document document{};
    document << "device_id" << deviceId
             << "data" << data
             << "timestamp" << bsoncxx::types::b_date{std::chrono::system_clock::now()};

    collection.insert_one(document.view());
}

void fetchAllDeviceData(const Config& config) {
    auto db = DatabaseManager::getDatabase(config.db_name);
    auto collection = db[config.collection_name];
    auto cursor = collection.find({});

    for (const auto& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
}
