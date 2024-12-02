#include "mongodb_handler.h"
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

mongocxx::pool MongoDBHandler::pool{mongocxx::uri{}};

void MongoDBHandler::initialize(const Config& config) {
    auto client = pool.acquire();
    db = (*client)[config.db_name];
    collection_name = config.collection_name;
}

void MongoDBHandler::insertDeviceData(int deviceId, int data) {
    auto collection = db[collection_name];
    bsoncxx::builder::stream::document document{};
    document << "device_id" << deviceId
             << "data" << data
             << "timestamp" << bsoncxx::types::b_date{std::chrono::system_clock::now()};

    collection.insert_one(document.view());
}

std::vector<DataEntry> MongoDBHandler::fetchAllDeviceData() {
    auto collection = db[collection_name];
    auto cursor = collection.find({});
    std::vector<DataEntry> dataEntries;

    for (const auto& doc : cursor) {
        DataEntry entry;
        entry.deviceId = doc["device_id"].get_int32();
        entry.data = doc["data"].get_int32();
        dataEntries.push_back(entry);
    }

    return dataEntries;
}

std::vector<DataEntry> MongoDBHandler::fetchDataByDevice(int deviceId) {
    auto collection = db[collection_name];
    bsoncxx::builder::stream::document filter{};
    filter << "device_id" << deviceId;
    auto cursor = collection.find(filter.view());
    std::vector<DataEntry> dataEntries;

    for (const auto& doc : cursor) {
        DataEntry entry;
        entry.deviceId = doc["device_id"].get_int32();
        entry.data = doc["data"].get_int32();
        dataEntries.push_back(entry);
    }

    return dataEntries;
}
