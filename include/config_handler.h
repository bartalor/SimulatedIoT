#ifndef CONFIG_HANDLER_H
#define CONFIG_HANDLER_H

#include <string>

struct Config {
    int num_threads;
    std::string db_name;
    std::string collection_name;
    std::string db_type; // New field for database type
    int min_data;
    int max_data;
};

Config loadConfig(const std::string& filename);

#endif
