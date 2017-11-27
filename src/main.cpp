#include <iostream>
#include <GL/gl3w.h>
#include "windowsystem.hpp"
#include "entity.hpp"
using namespace std;

void initGL()
{
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

#ifdef _WIN32
int wmain()
#else
int main()
#endif
{
    Window window{"Finger Soccer!!!", 1920, 1080, WindowProperty::RESIZEABLE};

    initGL();

    Entity ent;

    ent.addComponent<TransformComponent>();
    ent.addComponent<RigidBodyCompont>();

    while(window.isOpen())
    {        
        window.pollEvents();
        draw();
        window.display();
    }

    cout << "Everything is clean now!" << endl;
    return EXIT_SUCCESS;
}
