cmake_minimum_required(VERSION 3.15)
project(pathfinding CXX)

find_package(nlohmann_json)
find_package(spdlog)
find_package(GTest)
find_package(fmt)

add_library(pathfinding src/pathfinding.cpp)
target_include_directories(pathfinding PUBLIC include nlohmann_json::nlohmann_json spdlog::spdlog fmt::fmt)



set_target_properties(pathfinding PROPERTIES PUBLIC_HEADER "include/pathfinding.h")
install(TARGETS pathfinding)
