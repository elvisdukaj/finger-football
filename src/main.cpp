#include <iostream>
#include <gl/gl3w.h>
#include <SDL2/SDL.h>
using namespace std;

void initGL()
{
    gl3wInit();
    glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
    SDL_GL_SetSwapInterval(1);
}

void draw(SDL_Window* window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}

int wmain()
{
    cout << "Hello World!" << endl;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    auto window = SDL_CreateWindow(
                "My cool game", 0, 0, 800, 600
                , SDL_WINDOW_OPENGL
                | SDL_WINDOW_RESIZABLE
                | SDL_WINDOW_SHOWN
                );
    auto context = SDL_GL_CreateContext(window);

    for (auto minor = 0; minor < 7; ++minor)
    {
        cout << "OpenGL 4." << minor << " is "
             << boolalpha
             << (gl3wIsSupported(4, minor) ? " supported" : " not supported")
             << endl;
    }

    initGL();

    SDL_Event event;
    bool canExit = false;

    while(!canExit)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                canExit = true;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    canExit = true;
            }
        }

        draw(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    cout << "Everything is clean now!" << endl;
    return EXIT_SUCCESS;
} 
