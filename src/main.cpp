#include <GLFW/glfw3.h>
#include <cstddef>
#include <cstdio>

void handle_error(int error_code, const char* description);

int main() {
    if (!glfwInit()) {
        return -1;
    }

    glfwSetErrorCallback(handle_error);
    GLFWwindow* wnd = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    if (!wnd) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(wnd);
    while (!glfwWindowShouldClose(wnd)) {
    }

    glfwDestroyWindow(wnd);
    glfwTerminate();
}

void handle_error(int error_code, const char* description) {
    fprintf(stderr, "[GLFW] Error (code %d): %s\n", error_code, description);
}
