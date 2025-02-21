cmake_minimum_required(VERSION 3.23)
project(LongArithmetic)

set(CMAKE_CXX_STANDARD 20)

file(GLOB BIGDECIMAL_SOURCES
        src/bigDecimalConstructor.cpp
        src/bigDecimalArithmeticOperators.cpp
        src/bigDecimalLogicOperators.cpp
)

add_library(BIGDECIMAL ${BIGDECIMAL_SOURCES}
        src/bigDecimalLogicOperators.cpp)

add_executable(
        testsLogic
        tests/testLogic.cpp
)

add_executable(
        testsAdd
        tests/testsAdd.cpp
)

add_executable(
        testsMul
        tests/testMul.cpp
)

add_executable(
        testsDiv
        tests/testDiv.cpp
)

add_executable(
        testsPi
        tests/testPi.cpp
)

add_executable(
        LongArithmetic
        main.cpp 
)

target_link_libraries(LongArithmetic BIGDECIMAL)
target_link_libraries(testsAdd BIGDECIMAL)
target_link_libraries(testsLogic BIGDECIMAL)
target_link_libraries(testsMul BIGDECIMAL)
target_link_libraries(testsDiv BIGDECIMAL)
target_link_libraries(testsPi BIGDECIMAL)

set_target_properties(testsLogic PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)
set_target_properties(testsAdd PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)
set_target_properties(testsMul PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)
set_target_properties(testsDiv PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)
set_target_properties(testsPi PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)