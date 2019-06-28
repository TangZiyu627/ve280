#ifndef GAME_H
#define GAME_H

#include "const.h"
#include "tile.h"
#include "grid.h"

class Game {
    Grid grid;
    unsigned int score; // Record the accumulated score.
    unsigned int numTiles; // Store the number of tiles in the tiles array.
    Tile tiles[MAXTILES]; // An array that stores the information of all the tile types
public:
    Game(unsigned int height, unsigned int width, Tile tiles[], unsigned int numTiles);
    /* 
    // MODIFIES: this
    // EFFECTS: Store all the tile type in this->tiles
    //          Create "STARTTILES" new tiles.
    */

    void debugGrid();
    /* 
    // EFFECTS: Set a sample grid for debugging.
    */ 

    void newTile();
    /* 
    // MODIFIES: this
    // EFFECTS: Randomly create new tiles on the grid.
    //          Only "2" or "4" allowed to be created.
    //          Higher level tiles will not be created.
    */ 

    void collapseTiles(Direction dir);
    /* 
    // MODIFIES: this
    // EFFECTS: Call grid.collapseTiles
    //          Accumulate the score
    */ 

    bool shiftTiles(Direction dir);
    /* 
    // MODIFIES: this
    // EFFECTS: Call grid.shiftTiles
    //          Return whether there's shifted tiles.
    */ 

    bool checkWin() const;
    /* 
    // EFFECTS: Return whether there's a square of WINPOINTS
    //          tile, e.g. "2048"
    */ 

    bool checkLose() const;
    /* 
    // EFFECTS: Return whether there's no feasible move.
    //          If every square is full and any operation
    //          on any direction does not lead a tile to shift,
    //          then the game is over.
    */ 

    void printWin() const;
    /* 
    // EFFECTS: Print the winning message.
    */ 

    void printLose() const;
    /* 
    // EFFECTS: Print the losing message.
    */ 

    void printGame() const;
    /* 
    // EFFECTS: Print the game interface.
    */ 
};

#endif
