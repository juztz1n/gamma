#ifndef EXAMPLE_PROJECT_H
#define EXAMPLE_PROJECT_H

#include <iostream>

#include "../gamma_source/core/engine.h"
#include "../gamma_source/core/project.h"
#include "../gamma_source/math/vector3.h"

using namespace Gamma;

#define TITLE "Example Project"
#define WIDTH 1280
#define HEIGHT 720
#define STATE DisplayState::WINDOWED

#define UPDATE_RATE 60

class ExampleProject : public Project
{
    public:
        ExampleProject() : Project(TITLE, WIDTH, HEIGHT, STATE, UPDATE_RATE)
        {
        }

        Object object;
        Component component;
        void init() override
        {
            object = Object("Example Object");
            component = Component("Example Component");
            object.addComponent(component);

            addObject(object);
        };

        void loop() override
        {
            if (getEngine()->getDisplay()->isKeyDown(GLFW_KEY_ESCAPE))
                requestClose();
        };
};

#endif
