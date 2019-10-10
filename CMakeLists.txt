cmake_minimum_required(VERSION 2.8)
project(bouncer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cc"
)

add_executable(bouncer ${SOURCES})



