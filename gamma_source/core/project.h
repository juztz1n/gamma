#ifndef GAME_H
#define GAME_H

#include "engine.h"

#include "component_system.h"

#include "../graphics/display.h"

namespace Gamma
{
    class Engine;

    class Project
    {
        private:
            int width, height;
            const char* title;
            DisplayState state;

            int updateRate;

            Object* root;
            Engine* engine;

            bool closeRequested = false;

        public:
            Project(const char* title, int width, int height, DisplayState state, int updateRate);

            virtual void init() {}
            virtual void loop() {}
        
            Object* addObject(Object& object) { root->addChild(object); return &object; };
            Component* addComponent(Component& component) { root->addComponent(component); return &component; };

            const char* getTitle() { return title; }
            int getWidth() { return width; }
            int getHeight() { return height; }
            DisplayState getDisplayState() { return state; }
            int getUpdateRate() { return updateRate; }

            Object* getRootObject() { return root; }

            void requestClose() { closeRequested = true; }
            bool shouldClose() { return closeRequested; }

            void setEngine(Engine* engine) { this->engine = engine; }
            Engine* getEngine() { return engine; }

            ~Project();
    };
}

#endif
