cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_COMPILER "/usr/bin/g++-13")

project(Project LANGUAGES CXX)

add_library(figure src/figure.cpp src/triangle.cpp src/square.cpp src/octagon.cpp src/figure_array.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main figure)

set_target_properties(main PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON)

 add_subdirectory(
     "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
     "googletest"
 )
 add_executable(tests tests/point_test.cpp 
 tests/figure_test.cpp 
 tests/test_square.cpp
 tests/test_triangle.cpp
 tests/test_octagon.cpp
 tests/test_figure_array.cpp
 tests/test_integration.cpp)

 target_link_libraries(tests figure gtest gtest_main)
 enable_testing()
 add_test(NAME MoneyEdgeCaseTest COMMAND tests)
 add_test(NAME MoneyConstructorTest COMMAND tests)