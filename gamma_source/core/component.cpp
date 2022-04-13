#include "component_system.h"

using namespace Gamma;

Component::Component() : parent()
{
    name = "Unnamed";
}

Component::Component(const char* name) : parent()
{
    this->name = name;
}

bool Component::init()
{
    if (!parent)
    {
        err(std::string("There is no parent object. ").append(name));
        return false;
    }

    for (Component* component : subComponents)
        component->init();

    return true;
}

void Component::update()
{
    for (Component* component : subComponents)
        component->update();
}

void Component::preRender()
{
    for (Component* component : subComponents)
        component->preRender();
}

void Component::render()
{
    for (Component* component : subComponents)
        component->render();
}

void Component::postRender()
{
    for (Component* component : subComponents)
        component->postRender();
}

Component* Component::addSubComponent(Component& component)
{ 
    component.setParent(parent); 
    subComponents.push_back(&component); 
    
    return this; 
}

Component* Component::getSubComponent(const char* name) const
{
    for (Component* component : subComponents)
        if (component->getName() == name)
            return component;

    return NULL;
}