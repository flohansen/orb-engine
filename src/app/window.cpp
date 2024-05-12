#include "window.h"

namespace orb::app {

    Window::Window(unsigned int width, unsigned int height, const char* title) {
        m_wnd = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!m_wnd) {
            return;
        }

        glfwMakeContextCurrent(m_wnd);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwDestroyWindow(m_wnd);
            return;
        }
    }

    Window::~Window() {
        glfwDestroyWindow(m_wnd);
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
