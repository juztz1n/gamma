#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <iostream>

#include "logger.h"

#include "component.h"

namespace Gamma
{
    class Component;

    /**
     * @brief Objects are the abstraction that the engine/framework uses to initialize, update, render, and manage data. Objects use a list of components to break down the more intrecate details to more managable and modular parts.
     */
    class Object
    {
        private:
            Object* parent;
            std::vector<Object*> children;
            std::vector<Component*> components;

            const char* name;

        public:
            Object();
            
            Object(const char* name);

            virtual void init();
            virtual void update();
            virtual void preRender();
            virtual void render();
            virtual void postRender();

            Object* getParent() const { return parent; } 
            void setParent(Object* parent) { this->parent = parent; }

            Component* addComponent(Component& comp);
            Component* getComponent(const char* name) const;
            std::vector<Component*>* getComponents() { return &components; }

            Object* addChild(Object& object);
            Object* getChild(const char* name) const;
            std::vector<Object*>* getChildren() { return &children; }

            const char* getName() const { return name; }
    };
}

#endif