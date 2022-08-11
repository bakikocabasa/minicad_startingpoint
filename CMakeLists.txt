cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)

project(MINICAD
        VERSION 1.0
        DESCRIPTION "An example project with CMake"
        LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(app minicad)

file(GLOB_RECURSE SRCS model/*.cpp model/*.h ui/*.cpp ui/*.h main.cpp)

add_executable(${app} ${SRCS})

target_include_directories(${app} PRIVATE . model ui/ncurses ui/commands)

target_compile_options(${app} PRIVATE -Wall)

find_package(Curses REQUIRED)
target_include_directories(${app} PRIVATE src ${CURSES_INCLUDE_DIR})
target_link_libraries(${app} PRIVATE ${CURSES_LIBRARIES})