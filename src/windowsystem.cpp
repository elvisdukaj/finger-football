#include "windowsystem.hpp"
#include <GL/gl3w.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

Window::Window(const char *title, int width, int height, WindowProperty winProp)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_Quit();
        throw runtime_error{"SDL Initialization failed"};
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 2);    

    auto winFlags = winProp == WindowProperty::FULLSCREEN
            ? SDL_WINDOW_FULLSCREEN
            : SDL_WINDOW_RESIZABLE;

    m_window = SDL_CreateWindow(title, 0, 0, width, height,
                                SDL_WINDOW_OPENGL | winFlags
                );

    if (m_window == nullptr)
    {
        SDL_Quit();
        throw runtime_error{"Unable to create Main Window"};
    }

    m_context = SDL_GL_CreateContext(m_window);

    if (m_context == nullptr)
    {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        throw runtime_error{"Unable to initialize OpenGL Context"};
    }

    SDL_GL_MakeCurrent(m_window, m_context);

    if (gl3wInit())
    {
        SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        throw runtime_error{"Unable to initialize OpenGL"};
    }
}

Window::~Window()
{
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Window::pollEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch(event.type) {
        case SDL_APP_TERMINATING:
        case SDL_QUIT:
            m_isOpen = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                m_isOpen = false;
            break;

            case SDL_
        }
    }
}

void Window::display()
{
    SDL_GL_SwapWindow(m_window);
}
