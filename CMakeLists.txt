cmake_minimum_required(VERSION 3.16)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add cmake helper to fetch GoogleTest
include(cmake/GoogleTest.cmake)
include(GoogleTest)

enable_testing()

# Add each problem subdirectory automatically
file(GLOB CHILD_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "problems/*")
foreach(dir ${CHILD_DIRS})
    if (IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${dir}")
        add_subdirectory("${dir}")
    endif()
endforeach()
