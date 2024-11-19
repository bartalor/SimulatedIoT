#include "database_handler.h"
#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

static mongocxx::instance instance{};
static mongocxx::client client{mongocxx::uri{}};
static auto db = client["IoTDatabase"];

void initDatabaseClient() {
    std::cout << "Connected to MongoDB successfully." << std::endl;
}

void insertDeviceData(int deviceId, int data) {
    bsoncxx::builder::stream::document document{};
    document << "device_id" << deviceId
             << "data" << data
             << "timestamp" << bsoncxx::types::b_date{std::chrono::system_clock::now()};

    db["DeviceData"].insert_one(document.view());
    std::cout << "Data inserted for device " << deviceId << ": " << data << std::endl;
}

void fetchAllDeviceData() {
    auto collection = db["DeviceData"];
    auto cursor = collection.find({});

    std::cout << "Device Data from MongoDB: " << std::endl;
    for (const auto& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
}
