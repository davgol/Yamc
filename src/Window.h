//
// Created by David Goldring on 2023-02-03.
//

#ifndef YAMC_WINDOW_H
#define YAMC_WINDOW_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <string>

class Window {
public:
    explicit Window(std::string title);
    ~Window();
    void SetFullscreen(const bool fullscreen);
private:
    GLFWwindow* glfwWindow_ {NULL};
    bool fullscreen_ {false};
    unsigned int height_ {768};
    unsigned int width_ {1024};
};

void onKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
void onScrollCallback(GLFWwindow *window, double xdelty, double ydelta);

#endif //YAMC_WINDOW_H
