cmake_minimum_required(VERSION 3.10)

project(lab7_oop)

set(CMAKE_CXX_STANDARD             17)
set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

find_package(Catch REQUIRED)

include(cmake/BuildFlags.cmake)
include(cmake/TestSolution.cmake)


add_subdirectory(multiplication)
add_subdirectory(oop_complex)
add_subdirectory(vector)
