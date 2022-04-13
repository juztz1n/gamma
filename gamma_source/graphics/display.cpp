#include "display.h"

using namespace Gamma;

Display::Display(const char* title, int width, int height, DisplayState state)
{
    this->title = title;
    this->width = width;
    this->height = height;
}

bool Display::create()
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    switch(state)
    {
        case WINDOWED:
            identifier = glfwCreateWindow(width, height, title, 0, 0);
            break;
        case BORDERLESS:
            glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
            identifier = glfwCreateWindow(width, height, title, 0, 0);
            break;
        case FULLSCREEN:
            identifier = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), 0);
            break;
    }

    glfwMakeContextCurrent(identifier);

    glfwSwapInterval(0);

    return true;
}

void Display::update()
{
    glfwPollEvents();
    glfwSwapBuffers(identifier);
}


void Display::hide()
{
    glfwHideWindow(identifier);
}

void Display::show()
{
    glfwShowWindow(identifier);
}


bool Display::shouldClose()
{
    return glfwWindowShouldClose(identifier);
}


Display::~Display()
{
    glfwDestroyWindow(identifier);
}