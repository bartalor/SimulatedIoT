cmake_minimum_required(VERSION 3.10)
project(SimulatedIoTProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

find_package(mongocxx REQUIRED)
find_package(nlohmann_json REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/config_handler.cpp
    src/device_simulator.cpp
    src/simulation_manager.cpp
    src/mongodb_handler.cpp
    src/mongodb_data_analysis.cpp
    # Add other source files as needed
)

# Header files
set(HEADERS
    include/config_handler.h
    include/device_simulator.h
    include/simulation_manager.h
    include/database_interface.h
    include/mongodb_handler.h
    include/data_analysis_interface.h
    include/mongodb_data_analysis.h
    include/database_factory.h
    include/data_analysis_factory.h
    # Add other header files as needed
)

add_executable(SimulatedIoTProject ${SOURCES} ${HEADERS})

target_link_libraries(
    SimulatedIoTProject PRIVATE
    mongo::mongocxx_shared
    nlohmann_json::nlohmann_json
)
