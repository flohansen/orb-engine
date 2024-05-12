#include "window.h"
#include <GLFW/glfw3.h>

namespace orb::app {

    Window::Window(unsigned int width, unsigned int height, const char* title) {
        if (!glfwInit()) {
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_wnd = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!m_wnd) {
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_wnd);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwDestroyWindow(m_wnd);
            glfwTerminate();
            return;
        }
    }

    Window::~Window() {
        glfwDestroyWindow(m_wnd);
        glfwTerminate();
    }

    void Window::Run() const {
        while (!glfwWindowShouldClose(m_wnd)) {
            glViewport(0, 0, 800, 600);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(m_wnd);
            glfwPollEvents();
        }
    }

}
