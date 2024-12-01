#include "data_analysis.h"
#include "database_handler.h"
#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

static mongocxx::client client{mongocxx::uri{}};

void analyzeData(const Config& config) {
	auto db = DatabaseManager::getDatabase(config.db_name);
    auto collection = db[config.collection_name];
    auto cursor = collection.find({});
    
    int total = 0;
    int count = 0;
    for (const auto& doc : cursor) {
        int data = doc["data"].get_int32().value;
        total += data;
        count++;
    }

    if (count > 0) {
        std::cout << "Average device data: " << total / count << std::endl;
    } else {
        std::cout << "No data available for analysis." << std::endl;
    }
}

void analyzeDataByDevice(const Config& config, int deviceId) {
	auto db = DatabaseManager::getDatabase(config.db_name);
    auto collection = db[config.collection_name];
    
    // Create the filter using `bsoncxx::builder::basic::document`
    bsoncxx::builder::basic::document filter;
    filter.append(bsoncxx::builder::basic::kvp("device_id", deviceId));
    
    // Get the cursor for the filtered documents
    auto cursor = collection.find(filter.view());

    int total = 0;
    int count = 0;
    
    for (const auto& doc : cursor) {
        // Safely get the "data" field value
        if (doc["data"] && doc["data"].type() == bsoncxx::type::k_int32) {
            int data = doc["data"].get_int32().value;
            total += data;
            count++;
        }
    }

    if (count > 0) {
        std::cout << "Average data for device " << deviceId << ": " << total / count << std::endl;
    } else {
        std::cout << "No data available for device " << deviceId << "." << std::endl;
    }
}

void detectAnomalies(const Config& config) {
	auto db = DatabaseManager::getDatabase(config.db_name);
    auto collection = db[config.collection_name];
    auto cursor = collection.find({});

    for (const auto& doc : cursor) {
        int data = doc["data"].get_int32().value;
        if (data > 90) { // Arbitrary threshold for anomaly
            std::cout << "Anomaly detected! Device " << doc["device_id"].get_int32().value
                      << " sent unusually high data: " << data << std::endl;
        }
    }
}
