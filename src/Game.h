//
// Created by David Goldring on 2023-02-03.
//

#ifndef YAMC_GAME_H
#define YAMC_GAME_H


#include "Window.h"

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

    bool mIsRunning {false};
    Window *window_ {NULL};
};

#endif //YAMC_GAME_H
