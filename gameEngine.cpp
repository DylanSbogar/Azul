
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

void GameEngine::printPlayerMosaic(Player* player) {
     Tile** grid = player->getMosaic()->getGrid();
     Tile** patternLine = player->getMosaic()->getPatternLine();
     std::vector<Tile*> brokenTile = player->getMosaic()->getBrokenTiles();

     std::cout << "Mosaic for " << player->getPlayerName()<< ":" << std::endl;
     int num = 0;
     //prints first number for first row
     std::cout << ++num <<": ";
    //prints patternLine
     for(int i = 0; i < ROWS*COLS; ++i) {
        if(patternLine[i] != nullptr) 
            std::cout << patternLine[i]->getCharColour() << " ";

        else 
            std::cout << "*";

        if(i%5 == 4) {
            std::cout <<"||";
            //prints grid
             for(int a = 0; a < ROWS; ++a) {
                std::cout << grid[i]->getCharColour() << " ";   
            }
            std::cout << std::endl;
            //prints number for each row
            if(num<5){
                std::cout << ++num <<": ";}
        }
    }
    //prints broken tile
    std::cout << "broken: " ;
    for(int i = 0; i < brokenTile.size(); ++i){
        std::cout << brokenTile.at(i);
    }
     std::cout << std::endl;
    
}

// int GameEngine::calculatePlayerScores(Player* player) {

// }

// void GameEngine::addTilesToMosaicFromPatternLine(Player* player) {

// }
