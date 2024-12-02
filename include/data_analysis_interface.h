#ifndef DATA_ANALYSIS_INTERFACE_H
#define DATA_ANALYSIS_INTERFACE_H

class IDataAnalysis {
public:
    virtual ~IDataAnalysis() = default;

    virtual void analyzeData() = 0;
    virtual void analyzeDataByDevice(int deviceId) = 0;
    virtual void detectAnomalies() = 0;
};

#endif
