cmake_minimum_required(VERSION 3.10)
project(GTestProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Проверяем, установлен ли GTest в системе
find_package(GTest CONFIG)

if(NOT GTest_FOUND)
    message(STATUS "GTest не найден, загружаем через FetchContent...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)
endif()

enable_testing()
include(GoogleTest)

# Основной исполняемый файл
add_executable(main_app src/main.cpp src/math_utils.cpp)

# Тесты
add_executable(test_runner tests/test_math_utils.cpp src/math_utils.cpp)
target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(test_runner GTest::gtest GTest::gtest_main)

# Добавляем поддержку тестов
enable_testing()
add_test(NAME MathTests COMMAND test_runner)
