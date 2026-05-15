cmake_minimum_required(VERSION 3.24)
project(Google_tests)

add_subdirectory(lib)

add_executable(Google_Tests_run Testcases.cpp)

target_link_libraries(Google_Tests_run
        PRIVATE
        Code_library
        gtest
        gtest_main
)
