cmake_minimum_required(VERSION 3.10)
project(SimulatedIoTProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

find_package(mongocxx REQUIRED)
find_package(nlohmann_json REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(SimulatedIoTProject
	src/main.cpp
	src/device_simulator.cpp
	src/database_handler.cpp
	src/data_analysis.cpp
    src/config_handler.cpp
    src/simulation_manager.cpp
)

target_link_libraries(
	SimulatedIoTProject PRIVATE 
	mongo::mongocxx_shared 
	nlohmann_json::nlohmann_json
)