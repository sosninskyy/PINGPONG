cmake_minimum_required(VERSION 3.14)

project(PingPong C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)

FetchContent_MakeAvailable(raylib)

add_executable(PingPong WIN32 src/main.c src/pingpong/ballandpaddle.c)

target_include_directories(PingPong PRIVATE include)

target_link_libraries(PingPong PRIVATE raylib)