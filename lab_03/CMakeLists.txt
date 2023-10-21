cmake_minimum_required(VERSION 3.12)

set(CXX_STANDARD 17)

project(lab03)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/include
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        option(LAB03_TESTS "build tests (or no)" ON)

        if (LAB03_TESTS)
                add_library(example_google_tests ${all_SRCS})
                enable_testing()
                add_subdirectory(test)
        endif()
endif()

add_executable(app ${all_SRCS})
