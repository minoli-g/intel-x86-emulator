cmake_minimum_required(VERSION 3.15)
project(intel-x86-emulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")
file(GLOB_RECURSE HPP_SOURCES "src/*.hpp")

add_executable(intel-x86-emulator main.cpp ${CPP_SOURCES} ${HPP_SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(ie-test test/Test.cpp ${CPP_SOURCES} ${HPP_SOURCES})

target_link_libraries(ie-test GTest::gtest_main)
gtest_discover_tests(ie-test)
