cmake_minimum_required (VERSION 3.24.0)

project (sh_path)

include_directories(./algorithm)
include_directories(./generator)
include_directories(./headers)
include_directories(./tests)

set(ALGO_S ./algorithm/algorithm.cpp)
set(ALGO_H ./algorithm/algorithm.h)
add_library(algorithm_lib ${ALGO_S} ${ALGO_H})

set(GEN_S ./generator/generator.cpp)
set(GEN_H ./generator/generator.h)
add_library(generator_lib ${GEN_S} ${GEN_H})

set(TEST_S ./tests/tests.cpp)
set(TEST_H ./tests/tests.h)
add_library(tests_lib ${TEST_S} ${TEST_H})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} algorithm_lib)
target_link_libraries(${PROJECT_NAME} generator_lib)
target_link_libraries(${PROJECT_NAME} tests_lib)