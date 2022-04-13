#include "project.h"

using namespace Gamma;

Project::Project(const char* title, int width, int height, DisplayState state, int updateRate)
{
    this->title = title;
    this->width = width;
    this->height = height;
    this->state = state;
    this->updateRate = updateRate;

    root = new Object("root");
}

Project::~Project()
{
    delete root;
}