cmake_minimum_required(VERSION 3.10)

# set the project name
project(spch)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(spch src/main.cpp src/dictionary.cpp src/timer.cpp)

install(TARGETS spch DESTINATION bin)