#ifndef MONGODB_DATA_ANALYSIS_H
#define MONGODB_DATA_ANALYSIS_H

#include "data_analysis_interface.h"
#include "config_handler.h"
#include "database_interface.h"

class MongoDBDataAnalysis : public IDataAnalysis {
public:
    MongoDBDataAnalysis(const Config& config, IDatabase& db);

    void analyzeData() override;
    void analyzeDataByDevice(int deviceId) override;
    void detectAnomalies() override;

private:
    const Config& config;
    IDatabase& db;
};

#endif // MONGODB_DATA_ANALYSIS_H
