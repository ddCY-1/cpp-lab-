cmake_minimum_required(VERSION 3.20)
project(cpp_lab CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic -g)

add_library(lab src/stats.cpp)
target_include_directories(lab PUBLIC src)

add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE lab)

enable_testing()
add_executable(test_stats tests/test_stats.cpp)
target_link_libraries(test_stats PRIVATE lab)
add_test(NAME stats COMMAND test_stats)
