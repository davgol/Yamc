//
// Created by David Goldring on 2023-02-03.
//

#include "Window.h"
#include <iostream>

Window::Window(const std::string title) {

    if (! glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        std::exit(1);
    }

    GLFWmonitor *monitor = NULL;

    if (fullscreen_) {
        monitor = glfwGetPrimaryMonitor();
        int modesCount;
        const GLFWvidmode *modes = glfwGetVideoModes(monitor, &modesCount);
        height_ = modes[modesCount - 1].height;
        width_ = modes[modesCount - 1].width;
    }

    glfwWindow_ = glfwCreateWindow(width_, height_, title.c_str(), monitor, NULL);
    if (glfwWindow_ == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        std::exit(1);
    }

    glfwMakeContextCurrent(glfwWindow_);
    glfwSwapInterval(1);
    glfwSetInputMode(glfwWindow_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(glfwWindow_, onKeyCallback);
    glfwSetMouseButtonCallback(glfwWindow_, onMouseButtonCallback);
    glfwSetScrollCallback(glfwWindow_, onScrollCallback);
    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        std::exit(1);
    }
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glLogicOp(GL_INVERT);
    glClearColor(0, 0, 0, 1);

}

Window::~Window() {
    glfwTerminate();
}

void Window::SetFullscreen(const bool fullscreen) {
    this->fullscreen_ = fullscreen;
}

void onKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
}

void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
}

void onScrollCallback(GLFWwindow *window, double xdelty, double ydelta) {
}
