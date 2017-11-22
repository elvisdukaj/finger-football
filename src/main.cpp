#include <iostream>
//#include <GLES3/gl3.h>
#include <GL/gl3w.h>
#include <SDL2/SDL.h>
#include <imgui.h>
#include "imgui_impl_sdl_gl3.h"
using namespace std;

void initGL()
{
    gl3wInit();
    glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
}

void draw(SDL_Window* window)
{
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}

int main()
{
    cout << "Hello World!" << endl;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    auto window = SDL_CreateWindow(
                "My cool game", 0, 0, 800, 600
                , SDL_WINDOW_OPENGL
                | SDL_WINDOW_RESIZABLE
                | SDL_WINDOW_SHOWN
                );
    auto context = SDL_GL_CreateContext(window);

//    ImGui_ImplSdlGL3_Init(window);

    initGL();

    SDL_Event event;
    bool canExit = false;

    while(!canExit)
    {
        while (SDL_PollEvent(&event))
        {
//            ImGui_ImplSdlGL3_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                canExit = true;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    canExit = true;
            }
        }

//        ImGui_ImplSdlGL3_NewFrame(window);
//        ImGui::Begin("A Window", nullptr);
//        ImGui::Text("Hello from another window!");
//        ImGui::End();

        draw(window);
//        ImGui::Render();
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    cout << "Everything is clean now!" << endl;
    return EXIT_SUCCESS;
}
