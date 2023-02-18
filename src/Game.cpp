//
// Created by David Goldring on 2023-02-03.
//

#include "Game.h"
#include "Window.h"

#include <iostream>

Game::Game() {

}

bool Game::Initialize() {
    Window window("Yamc");

    return mIsRunning = true;
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

