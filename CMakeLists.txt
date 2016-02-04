cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -std=c++11 -fPIC ")

enable_testing()
find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
