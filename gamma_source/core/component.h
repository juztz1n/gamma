#ifndef PROJECT_H
#define PROJECT_H

#include <vector>

#include "logger.h"

#include "object.h"

namespace Gamma
{
    class Object;

    /**
     * @brief Component classes can be inhereted by other classes to make more complex behavior happen. You can then add and stack these components to a Object to access more data. Such as position, rotation, and scale data.
     */
    class Component
    {
        private:
            Object* parent;
            std::vector<Component*> subComponents;

            const char* name;

        public:
            Component();
            
            Component(const char* name);

            virtual bool init();
            virtual void update();
            virtual void preRender();
            virtual void render();
            virtual void postRender();


            Object* getParent() const { return parent; } 
            void setParent(Object* parent) { this->parent = parent; }
            
            Component* addSubComponent(Component& component);
            Component* getSubComponent(const char* name) const;
            std::vector<Component*>* getSubComponents() { return &subComponents; }

            const char* getName() const { return name; }
    };
}

#endif