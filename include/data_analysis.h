#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>

void analyzeData();
void analyzeDataByDevice(int deviceId);
void detectAnomalies();

#endif // DATA_ANALYSIS_H
