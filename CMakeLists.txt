cmake_minimum_required(VERSION 3.7)
project(TSP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp City/city_t.cpp City/city_t.h Utils/describable_t.cpp Utils/describable_t.h City/location_t.cpp City/location_t.h Tours/tour_manager_t.cpp Tours/tour_manager_t.h Tours/tour_t.cpp Tours/tour_t.h GA/population_t.cpp GA/population_t.h GA/GA.cpp GA/GA.h Utils/file_reader_t.cpp Utils/file_reader_t.h Tours/tour_base_t.cpp Tours/tour_base_t.h)
add_executable(TSP ${SOURCE_FILES})