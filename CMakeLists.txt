cmake_minimum_required(VERSION 3.15)
project(intel-x86-emulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")
file(GLOB_RECURSE HPP_SOURCES "src/*.hpp")

add_executable(intel-x86-emulator main.cpp ${CPP_SOURCES} ${HPP_SOURCES})
