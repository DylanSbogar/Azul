
#include "gameEngine.h"

GameEngine::GameEngine() {

}

GameEngine::GameEngine(const GameEngine& other) {

}

GameEngine::GameEngine(GameEngine&& other) {

}

GameEngine::~GameEngine() {

}

void GameEngine::runGame() {

}

void GameEngine::addTileFromFactoryToMosaic() {

}

void GameEngine::printPlayerMosaic(player* player) {
     Tile** grid = player->getMosaic()->getGrid();
     Tile** patternLine = player->getMosaic()->getPatternLine();
        for(int i = 0; i < ROWS; ++i) {
             for(int j = 0; j < COLS; ++j) {
            std::cout << grid[i]->getCharColour() << "|" << patternLine[i];
        }
        std::cout << std::endl;
    }

}

// int GameEngine::calculatePlayerScores(Player* player) {

// }

// void GameEngine::addTilesToMosaicFromPatternLine(Player* player) {

// }
