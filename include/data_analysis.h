#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H

#include "config_handler.h"
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>

void analyzeData(const Config& config);
void analyzeDataByDevice(const Config& config, int deviceId);
void detectAnomalies(const Config& config);

#endif // DATA_ANALYSIS_H
