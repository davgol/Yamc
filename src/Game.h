//
// Created by David Goldring on 2023-02-03.
//

#ifndef YAMC_GAME_H
#define YAMC_GAME_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Game {
public:
    Game();
    bool Initialize();
    void RunLoop();
    void Shutdown();

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    bool mIsRunning = true;
    bool mWandFullScreen = false;
    unsigned int mWindowHeight = 768;
    unsigned int mWindowWidth = 1024;

    GLFWwindow *mWindow = NULL;
};

void onKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
void onScrollCallback(GLFWwindow *window, double xdelty, double ydelta);


#endif //YAMC_GAME_H
