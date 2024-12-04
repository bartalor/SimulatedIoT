cmake_minimum_required(VERSION 3.10)
project(SimulatedIoTProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build type and flags
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Required packages
find_package(mongocxx REQUIRED)
find_package(nlohmann_json REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

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
)

add_executable(SimulatedIoTProject ${SOURCES} ${HEADERS})

target_link_libraries(
    SimulatedIoTProject PRIVATE
    mongo::mongocxx_shared
    nlohmann_json::nlohmann_json
)

include(CTest)

find_package(GTest REQUIRED)

set(TEST_SOURCES
    tests/test_config_handler.cpp
)

add_executable(SimulatedIoTTests ${TEST_SOURCES})

target_link_libraries(
    SimulatedIoTTests PRIVATE
    GTest::GTest
    GTest::Main
    SimulatedIoTProject
)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(SimulatedIoTTests)
