#include "component_system.h"

using namespace Gamma;

Object::Object() : parent() 
{
    name = "Unnamed";
}

Object::Object(const char* name) : parent()
{
    this->name = name;
}

void Object::init()
{
    for (Object* object : children)
        object->init();
        
    for (Component* component : components)
        if (!component->init())
            err(std::string("Failed to initialize component. ").append(name));
}

void Object::update()
{
    for (Object* object : children)
        object->update();
        
    for (Component* component : components)
        component->update();
}

void Object::preRender()
{
    for (Object* object : children)
        object->preRender();
}

void Object::render()
{
    for (Component* component : components)
        component->preRender();
    
    for (Object* object : children)
        object->render();

    for (Component* component : components)
        component->postRender();
}

void Object::postRender()
{
    for (Object* object : children)
        object->postRender();
}

Component* Object::addComponent(Component& component)
{
    component.setParent(this);
    components.push_back(&component);

    return &component;
}

Object* Object::addChild(Object& object)
{
    object.setParent(this);
    children.push_back(&object);

    return &object;
}


Component* Object::getComponent(const char* name) const
{
    for (Component* component : components)
        if (component->getName() == name)
            return component;

    return NULL;
}

Object* Object::getChild(const char* name) const
{
    for (Object* object : children)
        if (object->getName() == name)
            return object;

    return NULL;
}