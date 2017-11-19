cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(finger-football)

set(SRC_LIST "src/main.cpp")

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extlibs)
find_package(SDL2 CONFIG REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
