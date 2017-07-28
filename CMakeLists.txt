cmake_minimum_required(VERSION 3.7)
project(TSP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp city_t.cpp city_t.h describable_t.cpp describable_t.h location_t.cpp location_t.h tour_manager_t.cpp tour_manager_t.h tour_t.cpp tour_t.h population_t.cpp population_t.h GA.cpp GA.h file_reader_t.cpp file_reader_t.h)
add_executable(TSP ${SOURCE_FILES})