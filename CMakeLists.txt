cmake_minimum_required(VERSION 3.24)
project(MISS)

set(CMAKE_CXX_STANDARD 23)

add_executable(MISS main.cpp DrawingEngine.cpp DrawingEngine.h Simulation.cpp Simulation.h Agent.cpp Agent.h Simulation.cpp GraphDrawer.cpp GraphDrawer.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(MISS ${SFML_LIBRARIES})
endif()