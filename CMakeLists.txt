cmake_minimum_required(VERSION 3.15)
project(intel-x86-emulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES *.cpp *.hpp **/*.cpp **/*.hpp)

add_executable(intel-x86-emulator ${SOURCES})
