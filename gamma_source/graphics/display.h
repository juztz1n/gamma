#ifndef DISPLAY_H
#define DISPLAY_H

#include <GLFW/glfw3.h>

namespace Gamma
{
    enum DisplayState
    {
        WINDOWED, BORDERLESS, FULLSCREEN
    };

    /**
     * @brief This class is responsible for managing the window, and giving all the helper functions needed for keyboard and mouse inputs, updating the window, hiding/showing the window, and much more.
     */
    class Display
    {
        private:
            int width, height;
            const char* title;

            DisplayState state;

            GLFWwindow* identifier;

        public:
            Display(const char* title, int width, int height, DisplayState state);

            bool create();
            void update();

            void hide();
            void show();

            bool shouldClose();

            const char* getTitle() { return title; }
            int getWidth() { return width; }
            int getHeight() { return height; }
            DisplayState getDisplayState() { return state; }
            GLFWwindow* getIdentifer() { return identifier; }

            bool isKeyDown(unsigned int key) 
            { return glfwGetKey(identifier, key) == GLFW_TRUE; }
            bool isMouseButtonDown(unsigned int button) 
            { return glfwGetMouseButton(identifier, button) == GLFW_TRUE; }

            ~Display();
    };
}

#endif
