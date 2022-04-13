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
