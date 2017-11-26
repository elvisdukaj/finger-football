#pragma once

#include <SDL2/SDL.h>

enum class WindowProperty {
    FULLSCREEN = 1,
    RESIZEABLE = 2
};

class Window {
public:
    Window(const char* title, int width, int height,
           WindowProperty winProp = WindowProperty::FULLSCREEN);
    ~Window();

    void pollEvents();
    void display();
    bool isOpen() const noexcept { return m_isOpen; }

private:
    SDL_Window* m_window;
    SDL_GLContext m_context;
    bool m_isOpen = true;
};
