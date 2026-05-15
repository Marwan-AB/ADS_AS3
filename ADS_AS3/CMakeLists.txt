cmake_minimum_required(VERSION 3.24)
project(Fall2025_assignment3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Code_library_run ${SOURCE_FILES})

include_directories(Code_library)
add_subdirectory(Code_library)

target_link_libraries(Code_library_run Code_library)

add_subdirectory(Google_tests)