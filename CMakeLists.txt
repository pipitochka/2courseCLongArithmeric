cmake_minimum_required(VERSION 3.25)
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
        testsArithmetic
        tests/testsArithmetic.cpp
)

add_executable(
        testsLogic
        tests/testLogic.cpp
)

add_executable(
        LongArithmetic
        main.cpp 
)

target_link_libraries(LongArithmetic BIGDECIMAL)
target_link_libraries(testsArithmetic BIGDECIMAL)
target_link_libraries(testsLogic BIGDECIMAL)


set_target_properties(testsLogic PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)
set_target_properties(testsArithmetic PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)