cmake_minimum_required(VERSION 3.10)
project(MatrixCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest CONFIG)
if(NOT GTest_FOUND)
    message(STATUS "GTest not found. Fetching via FetchContent...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(main_app src/main.cpp src/Matrix.cpp)
install(TARGETS main_app DESTINATION usr/local/bin)

enable_testing()
add_executable(test_runner tests/test_matrix.cpp src/Matrix.cpp)
target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(test_runner GTest::gtest GTest::gtest_main)
add_test(NAME MatrixTests COMMAND test_runner)