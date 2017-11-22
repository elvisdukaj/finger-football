#include <iostream>
#include <GL/gl3w.h>
#include <SDL2/SDL.h>
#include <imgui.h>
#include "imgui_impl_sdl_gl3.h"
using namespace std;

ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
bool show_test_window = false;

void initGL()
{
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

int wmain()
{
    cout << "Hello World!" << endl;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        cerr << "Unable to initialize Window System" << endl;
        SDL_Quit();
        return EXIT_FAILURE;
    };

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 2);

    auto window = SDL_CreateWindow(
                "My cool game", 0, 0, 1366, 768
                , SDL_WINDOW_OPENGL
                | SDL_WINDOW_SHOWN
                | SDL_WINDOW_RESIZABLE
                );

    if (window == 0)
    {
        cerr << "Unable to create Main Window" << endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    auto context = SDL_GL_CreateContext(window);

    if (context == nullptr)
    {
        cerr << "Unable to initialize OpenGL Context" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_GL_MakeCurrent(window, context);

    if (gl3wInit())
    {
        cerr << "Unable to initialize OpenGL" << endl;
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    ImGui_ImplSdlGL3_Init(window);
    initGL();

    SDL_Event event;
    bool done = false;

    while(!done)
    {
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSdlGL3_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;
            }
        }


        ImGui_ImplSdlGL3_NewFrame(window);

        {
            static float f = 0.0f;
            ImGui::Text("Hello, world!");
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::ColorEdit3("clear color", (float*)&clear_color);
            if (ImGui::Button("Test Window")) show_test_window ^= 1;
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }

        if (show_test_window)
        {
            ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
            ImGui::ShowTestWindow(&show_test_window);
        }

        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        draw();

        ImGui::Render();
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    cout << "Everything is clean now!" << endl;
    return EXIT_SUCCESS;
}
