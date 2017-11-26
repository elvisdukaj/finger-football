cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(finger-football)


set(SRC_LIST
    "src/main.cpp"
    "src/entity.cpp"
    "src/gl3w.c"
    "src/imgui.cpp"
    "src/imgui_draw.cpp"
    "src/imgui_impl_sdl_gl3.cpp"
    "src/imgui_demo.cpp"
    "src/windowsystem.cpp"
    "src/gameobject.cpp"
    "src/gpu.cpp"
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(SDL2_DIR ${CMAKE_SOURCE_DIR}/extlibs/cmake)
#set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extlibs)

find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(${PROJECT_NAME}
PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    SDL2::SDL2
    OpenGL::GL
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    OpenGL::GL
    SDL2::SDL2-static
)
