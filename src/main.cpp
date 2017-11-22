#include <iostream>
#include <GL/gl3w.h>
#include <SDL2/SDL.h>
#include <imgui.h>
#include "imgui_impl_sdl_gl3.h"
using namespace std;

void initGL()
{
    glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{
    cout << "Hello World!" << endl;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        cerr << "Unable to initialize Window System" << endl;
        SDL_Quit();
        return EXIT_FAILURE;
    };

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
//    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    auto window = SDL_CreateWindow(
                "My cool game", 0, 0, 800, 600
                , SDL_WINDOW_OPENGL
                | SDL_WINDOW_SHOWN
                );

    if (window == 0)
    {
        cerr << "Unable to create Main Window" << endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    auto context = SDL_GL_CreateContext(window);

//    SDL_GL_MakeCurrent(window, context);

    if (gl3wInit())
    {
        cerr << "Unable to initialize OpenGL" << endl;
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

//    ImGui_ImplSdlGL3_Init(window);



    initGL();

    SDL_Event event;
    bool done = false;

    while(!done)
    {
        while (SDL_PollEvent(&event))
        {
//            ImGui_ImplSdlGL3_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;
            }
        }

//        ImGui_ImplSdlGL3_NewFrame(window);
//        ImGui::Begin("A Window", nullptr);
//        ImGui::Text("Hello from another window!");
//        ImGui::End();

        draw();
//        ImGui::Render();
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    cout << "Everything is clean now!" << endl;
    return EXIT_SUCCESS;
}
