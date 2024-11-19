cmake_minimum_required(VERSION 3.10)
project(SimulatedIoTProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) # Ensure C++17 is required

set(CMAKE_PREFIX_PATH "/usr/local/lib/cmake/bsoncxx-3.11.0;/usr/local/lib/cmake/mongocxx-3.11.0")
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

include_directories(include /usr/local/include/bsoncxx/v_noabi)

add_executable(SimulatedIoTProject src/main.cpp src/device_simulator.cpp src/database_handler.cpp src/data_analysis.cpp)

target_link_libraries(SimulatedIoTProject PRIVATE mongocxx bsoncxx)
