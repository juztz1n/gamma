#include "engine.h"

#include "logger.h"
#include "time.h"

using namespace Gamma;

void Engine::start()
{
    if (running)
        return;

    running = true;

    project->setEngine(this);

    display = new Display(project->getTitle(), project->getWidth(), project->getHeight(), project->getDisplayState());

	frameTime = 1.0 / project->getUpdateRate();

    if (!display->create())
    {
        std::cout << "Failed to create display. Exiting." << std::endl;
        exit(-1);
    }

    loop();
}

void Engine::loop()
{
	std::string glfw_version = (char*) glfwGetVersionString();

	info("Gamma Version: " GAMMA_VERSION ".");
	info("Engine starting.");
	info("GLFW Version: " + glfw_version + ".");

	project->init();
	project->getRootObject()->init();

	double lastTime = getTime();
	double unprocessedTime = 0, frameCounter = 0;
	int updates = 0, frames = 0;

	bool render;

	display->show();

	while (running)
	{
		render = false;

		double startTime = getTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime;
		frameCounter += passedTime;

		while (unprocessedTime > frameTime)
		{
			render = true;

			unprocessedTime -= frameTime;

			if (display->shouldClose() || project->shouldClose())
			{
				info("Close requested, engine stopping.");

				stop();
				break;
			}

			project->loop();

			updates++;
			project->getRootObject()->update();

			if (frameCounter >= 1.0)
			{
				std::cout << GAMMA_INFO_PREFIX << " Frame Rate: " 
					<< frames << ", Update Rate: " << updates << ".\r\n";

				frameRate = frames;
				updateRate = updates;

				fps.push_back(frames);
				ups.push_back(updates);

				frames = updates = 0;
				frameCounter = 0.0;
			}
		}

		if (render)
		{
			draw();
			frames++;
		}
	}
}

void Engine::draw()
{
	project->getRootObject()->preRender();
	project->getRootObject()->render();
	project->getRootObject()->postRender();

	display->update();
}

void Engine::stop()
{
	if (!running)
		return;

	display->hide();

	double fpsTotal = 0, upsTotal = 0;

	for (unsigned int i = 0; i < fps.size(); i++)
	{
		fpsTotal += fps.at(i);
		upsTotal += ups.at(i);
	}

	std::cout << GAMMA_INFO_PREFIX << " Total Frames Drawn: " << fpsTotal << "." << std::endl;
	std::cout << GAMMA_INFO_PREFIX << " Average Frames Per Second: " << (fpsTotal / fps.size()) << "." << std::endl;
	std::cout << GAMMA_INFO_PREFIX << " Average Updates Per Second: " << (upsTotal / fps.size()) << "." << std::endl;

	running = false;
}

Engine::~Engine()
{
    delete display;

    glfwTerminate();
}