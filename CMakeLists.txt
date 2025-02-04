cmake_minimum_required(VERSION 3.29)
project(LongArithmetic)

set(CMAKE_CXX_STANDARD 20)

file(GLOB BIGDECIMAL_SOURCES src/*.cpp)
add_library(BIGDECIMAL ${BIGDECIMAL_SOURCES})

add_executable(
        Tests
        tests/tests.cpp
)

add_executable(
        LongArithmetic
        main.cpp 
)

target_link_libraries(LongArithmetic BIGDECIMAL)
target_link_libraries(Tests BIGDECIMAL)