cmake_minimum_required(VERSION 3.10)
project(FactorialBenchmark)

set(CMAKE_CXX_STANDARD 11)

set(BENCHMARK_ENABLE_TESTING OFF)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_USE_BUNDLED_GTEST OFF)

add_subdirectory(benchmark-main)

add_executable(factorial_benchmark main.cpp)

target_link_libraries(factorial_benchmark benchmark::benchmark)