//
// Created by David Goldring on 2023-02-03.
//

#include "Game.h"

#include <iostream>
#include <random>

Game::Game() {

}

bool Game::Initialize() {
    std::srand(std::time(nullptr));
    std::rand();

    if (! glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    GLFWmonitor *monitor = NULL;

    if (mWandFullScreen) {
        monitor = glfwGetPrimaryMonitor();
        int modesCount;
        const GLFWvidmode *modes = glfwGetVideoModes(monitor, &modesCount);
        mWindowHeight = modes[modesCount -1].height;
        mWindowWidth = modes[modesCount -1].width;
    }
    mWindow = glfwCreateWindow(mWindowWidth, mWindowHeight, "Yamc", monitor, NULL);
    if (mWindow == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(mWindow);
    glfwSwapInterval(1);
    glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(mWindow, onKeyCallback);
    glfwSetMouseButtonCallback(mWindow, onMouseButtonCallback);
    glfwSetScrollCallback(mWindow, onScrollCallback);

    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return false;
    }


    return mIsRunning;
}

void Game::RunLoop() {
    while (mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown() {

    glfwTerminate();
}

void Game::ProcessInput() {

}

void Game::UpdateGame() {

    static int cnt = 1;
    if (cnt >= 3) {
        mIsRunning = false;
    }
    cnt++;
}

void Game::GenerateOutput() {
    std::cout << "Hello, World!" << std::endl;
}

void onKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {

}

void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {

}

void onScrollCallback(GLFWwindow *window, double xdelty, double ydelta) {

}
