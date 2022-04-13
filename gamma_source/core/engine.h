#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <vector>

#include "project.h"

#include "../graphics/display.h"

#define GAMMA_VERSION "0.1.0"

namespace Gamma
{
    class Project;

    /**
     * @brief The engine is responsible for managing all of the objects and thus components contained in the project. As well as an updates per second, and frames per second counter. 
     */
    class Engine
    {
        private:
            Project* project;
            
            Display* display;

            bool running = false;

			int frameRate, updateRate;
			double frameTime, passedTime;

			std::vector<int> fps;
			std::vector<int> ups;

        public:
            Engine(Project* project)
            {
                this->project = project;
            }

            void start();
            void loop();
            void draw();
            void stop();

            Display* getDisplay() { return display; }

            ~Engine();
    };
}

#endif
