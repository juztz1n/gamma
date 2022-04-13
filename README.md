# Gamma
This is primarily a project that I'm creating and maintaining to work as a framework/engine for all of my projects.

### Project Philosopy and Goals
- My goals/philosophy for the project:
    - Be able to jump in at any point of the program, without the need for pre-requisite knowledge.
    - Have everything available, but not need it. To hook-in what is needed as you go.
    - Make it extremely easy to create new things inside the program.
    - Create any project, and have it be able to run inside the browser.
    - VR rendering capabilities.
    - Optimization is one of the top priorities.
    - Physics engine.
- My goals personally:
    - Learn about all the different concepts needed to create a framework like this.
    - Become better at optimization, since real-time applications require lots of optimization.
    - Get more familiar with C/C++.
    - Learn more about how to program a physics engine.

## Installation

### Windows
The project files have only been tested and compiled on a Linux machine. Windows instructions will come out later on as the project grows more mature. But for now there is only the following Linux installation/setup process.

### Linux
There's a build shell script included with the project. You can run that by typing `./build_linux.sh` and that will output a project file to `a.out`. The different parts of the engine, are subdivided using folders. But if you want to use a feature the engine provides you can find it in `engine_source`. If you'd like to program your own project you should put it in `project_source`, but you don't have to.

#### Dependencies
There are no dependencies currently, the project compiles as plain C++ code.

#### Use in code
Use the following code to setup and start the engine in code.
```cpp
#include "../gamma_source/core/engine.h"

#include "example_project.h"

using namespace Gamma;

int main()
{
    Project* project = new ExampleProject();
    Engine* engine = new Engine(project);

    engine->start();

    delete engine;
    delete project;

    return 0;
}
```
You'll need to create and delete your own memory, since it is not managed by the framework. As you can see you'll need to pass in a reference of a class that inheretes the `Project` class. You can set up a project using the following class.
```cpp
#ifndef EXAMPLE_PROJECT_H
#define EXAMPLE_PROJECT_H

#include "../gamma_source/core/engine.h"
#include "../gamma_source/core/project.h"

using namespace Gamma;

#define TITLE "Example Project"
#define WIDTH 1280
#define HEIGHT 720
#define STATE DisplayState::WINDOWED

#define UPDATE_RATE 60

class ExampleProject : public Project
{
    public:
        ExampleProject() : Project(TITLE, WIDTH, HEIGHT, STATE, UPDATE_RATE) {}

        void init() override {};

        void loop() override {};
};

#endif
```
The previous code and a little more example code is included with the project inside the `project_source`, so you don't need to type all of this out yourself. 

When adding a new object use the following code:
```cpp
void init() override
{
    Object* object = new Object("Example Object");
    Component* component = new Component("Example Component");

    object->addComponent(component);

    addObject(object);
};
```
Keep in mind that the objects and components automatically get deleted by the engine itself, so no need to do memory management on that. As explained before, you're able to create custom components and/or objects by inheriting the `Object` or `Component` class. Obviously, you'd usually not just use an empty component.

## Features
Briefly, the engine has a built-in component system, so you can modularily add in features to a certain object. A math library equipped to do all the essential graphical calculations you'll be using.

#### Overview
- Component system.
- Math library:
    - Vectors.
    - Matrices.
    - Quaternions.

#### Planned Features
- Ability for 3d and 2d rendering.
    - Including VR rendering.
    - Ease of implementation of new graphical features.
- Interfaces, using JSX embeded into the application itself.
- Making everything runnable in the web browser and on a web server.
- Simple to use GUI editor.