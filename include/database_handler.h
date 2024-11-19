#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <string>

void initDatabaseClient();
void insertDeviceData(int deviceId, int data);
void fetchAllDeviceData();

#endif
