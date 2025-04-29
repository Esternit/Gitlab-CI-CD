cmake_minimum_required(VERSION 3.10)
project(MatrixCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPACK_PACKAGE_NAME "${CMAKE_PROJECT_NAME}")
set(CPACK_PACKAGE_CONTACT "southonlyyt@gmail.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Esternit")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")

set(CPACK_GENERATOR "DEB;RPM")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

set(CPACK_PACKAGE_VERSION "1.0.0")

set(CPACK_PACKAGE_DIRECTORY "${CMAKE_BINARY_DIR}/packages")

if(NOT DEFINED CMAKE_SYSTEM_NAME)
    set(CMAKE_SYSTEM_NAME Linux)
endif()

if(NOT DEFINED CPACK_SYSTEM_NAME)
    set(CPACK_SYSTEM_NAME ${CMAKE_SYSTEM_NAME})
endif()

include(InstallRequiredSystemLibraries)
include(CPack)

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

install(TARGETS main_app DESTINATION bin)

enable_testing()
add_executable(test_runner tests/test_matrix.cpp src/Matrix.cpp)
target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(test_runner GTest::gtest GTest::gtest_main)
add_test(NAME MatrixTests COMMAND test_runner)
