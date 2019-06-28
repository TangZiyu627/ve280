#include "game.h"
#include "const.h"
#include "tile.h"
#include "grid.h"
#include <iostream>

using namespace std;

Game::Game(unsigned int height, unsigned int width, Tile tiles[], unsigned int numTiles) :
        grid(height, width), score(0), numTiles(numTiles) {
    for (int i = 0; i < numTiles; i++) {
        this->tiles[i] = tiles[i];
    }
    for (int i = 0; i < STARTTILES; i++) {
        newTile();
    }
}

void Game::debugGrid() {
    grid.clearSquares();
    grid.setSquare({2, 1}, &tiles[0]);
    grid.setSquare({3, 3}, &tiles[1]);
    grid.setSquare({1, 0}, &tiles[2]);
    grid.setSquare({0, 3}, &tiles[0]);
    grid.setSquare({1, 2}, &tiles[3]);
    grid.setSquare({3, 1}, &tiles[0]);
    grid.setSquare({1, 1}, &tiles[0]);
    grid.setSquare({0, 1}, &tiles[0]);
}

void Game::newTile() {
    int count = 0;
    for (int i = 0; i < grid.getHeight(); i++) {
        for (int j = 0; j < grid.getWidth(); j++) {
            if (grid.isEmpty({i, j})) {
                count++;
            }
        }
    }
    if (!count) return;
    count = rand() % count;
    for (int i = 0; i < grid.getHeight(); i++) {
        for (int j = 0; j < grid.getWidth(); j++) {
            if (grid.isEmpty({i, j})) {
                if (count) {
                    count--;
                } else {
                    grid.setSquare({i, j}, rand() % 100 < TWOPERCENTAGE ? &tiles[0] : &tiles[1]);
                    return;
                }
            }
        }
    }
}

void Game::collapseTiles(Direction dir) {
    score += grid.collapseTiles(dir);
}

bool Game::shiftTiles(Direction dir) {
    return grid.shiftTiles(dir);
}

bool Game::checkWin() const {
    // TODO: Your implementation here
    return false;
}

bool Game::checkLose() const {
    // TODO: Your implementation here
    return false;
}

void Game::printWin() const {
    for (int i = 0; i < numTiles; i++) {
        if (tiles[i].points == WINPOINTS) {
            wcout << "You've reached tile " << tiles[i].value << ". Congratulations!" << endl;
        }
    }
}

void Game::printLose() const {
    wcout << "Game Over!" << endl;
}

void Game::printGame() const {
    system("clear");
    wcout << "Welcome to 2048!" << endl << endl;
    grid.printGrid();
    wcout << "Your score: " << score << endl;
}
