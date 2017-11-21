cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(finger-football)

set(SDL2_DIR ${CMAKE_SOURCE_DIR}/extlibs/cmake)

set(SRC_LIST
    "src/main.cpp"
    "src/gl3w.c"
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extlibs)
find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include SDL2::SDL2 OpenGL::GL)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL SDL2::SDL2-static)
