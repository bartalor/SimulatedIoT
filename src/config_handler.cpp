#include "config_handler.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

Config loadConfig(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open config file: " + filename);
    }

    nlohmann::json json;
    file >> json;

return {
    json["num_threads"],
    json["database"]["name"],
    json["database"]["collection"],
    json["database"]["type"], // Load the new field
    json["simulation"]["min_data"],
    json["simulation"]["max_data"]
};

}
