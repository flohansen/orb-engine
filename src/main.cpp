#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstddef>
#include <cstdio>

void handle_error(int error_code, const char* description);

int main() {
    if (!glfwInit()) {
        return -1;
    }

    glfwSetErrorCallback(handle_error);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* wnd = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    if (!wnd) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(wnd);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(wnd);
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(wnd)) {
        glViewport(0, 0, 800, 600);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(wnd);
        glfwPollEvents();
    }

    glfwDestroyWindow(wnd);
    glfwTerminate();
}

void handle_error(int error_code, const char* description) {
    fprintf(stderr, "[GLFW] Error (code %d): %s\n", error_code, description);
}
