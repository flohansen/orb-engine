#pragma once

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace orb::app {

    class Window {
    private:
        GLFWwindow* m_wnd;
    public:
        Window(unsigned int width, unsigned int height, const char* title);
        ~Window();
        void Run() const;
    };

}
