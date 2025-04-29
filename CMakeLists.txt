cmake_minimum_required(VERSION 3.10)
project(MatrixCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(main_app src/main.cpp src/Matrix.cpp)

install(TARGETS main_app DESTINATION bin)

include(CTest)
enable_testing()
add_executable(test_runner tests/test_matrix.cpp src/Matrix.cpp)
target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)
find_package(GTest REQUIRED)
target_link_libraries(test_runner GTest::gtest GTest::gtest_main)
add_test(NAME MatrixTests COMMAND test_runner)

include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "DEB;RPM")
set(CPACK_PACKAGE_NAME "matrix_calculator")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "southonlyyt@gmail.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Esternit")
include(CPack)