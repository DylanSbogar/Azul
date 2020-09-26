#include <iostream>
#include "tile.h"
#include "utils.h"
#include "mosaic.h"
#include "tileBag.h"
#include "factory.h"
#include "factories.h"
#include "gameEngine.h"

//IMPLEMENT TILE BAG GENERATOR
// void generateTileBagInstaces(); 

void testTileClass();
void testUtilsClass();
void testTileBagClass();
void testFactoryClass();
void testFactoriesClass();
void testMosaicClass();
void testGameEngineScoring();
void testGameEngineAddToGrid();


int main(void) {
    std::cout << "TESTING COMMENCING..." << std::endl;
    std::cout << std::endl;
    
    std::cout << "--Tile Class:--" << std::endl;
    testTileClass();
    std::cout << std::endl;

    std::cout << "--Mosaic Class:--" << std::endl;
    testMosaicClass();
    std::cout << std::endl;

    std::cout << "--Utils Class:--" << std::endl;
    testUtilsClass();
    std::cout << std::endl;

    std::cout << "--TileBag Class:--" << std::endl;
    testTileBagClass();
    std::cout << std::endl;

    std::cout << "--Factory Class:--" << std::endl;
    testFactoryClass();
    std::cout << std::endl;

    std::cout << "--Factories Class:--" << std::endl;
    testFactoriesClass();
    std::cout << std::endl;

    std::cout << "--Game Engine Class - SCORING:--" << std::endl;
    testGameEngineScoring();
    std::cout << std::endl;

    std::cout << "--Game Engine Class - ADD TO GRID:--" << std::endl;
    testGameEngineAddToGrid();
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

void testGameEngineAddToGrid() {
    GameEngine* gameEngine = new GameEngine();
    Player* player = new Player("Tom");

    //TEST 1 - Check not full patternLine isn't moved
    std::cout << "TEST 1 - Check not full patternLine isn't moved " << std::endl;
    std::cout << "Printing Blank Player Mosaic: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    player->getMosaic()->addTileToPatternLine(new Tile(RED), 4);


    std::cout << "Printing Player Mosaic With PatternLine Tiles: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    gameEngine->addTilesToMosaicFromPatternLine(player);    

    std::cout << "Printing Player Mosaic After Method Call: " << std::endl;
    gameEngine->printPlayerMosaic(player);
    std::cout << std::endl;

    //TEST 2 - Check that full patternLine is moved
    int patternLineRow = 1;

    std::cout << "Printing Blank Player Mosaic: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    while(!player->getMosaic()->patternLineFull(patternLineRow)) {
        player->getMosaic()->addTileToPatternLine(new Tile(YELLOW), patternLineRow);
    }

    std::cout << "Printing Player Mosaic With PatternLine Tiles: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    gameEngine->addTilesToMosaicFromPatternLine(player);    

    std::cout << "Printing Player Mosaic After Method Call: " << std::endl;
    gameEngine->printPlayerMosaic(player);
    std::cout << std::endl;

    delete gameEngine;
}

void testGameEngineScoring() {
    GameEngine* gameEngine = new GameEngine();
    Player* player = new Player("Tom");

    std::cout << "Printing Player Mosaic: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    int playerScore = gameEngine->calculatePlayerScores(player);

    std::cout << "Expected Score = 0 - Actual = " << playerScore << std::endl;
    std::cout << std::endl;

    //TEST 1 - ADD SINGLE TILE
    Tile* playerTile = player->getMosaic()->getGridTile(0, 4);
    delete playerTile;
    playerTile = new Tile(YELLOW);

    std::cout << "Printing Player Mosaic: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    playerScore = gameEngine->calculatePlayerScores(player);
    
    std::cout << "Expected Score = 1 - Actual = " << playerScore << std::endl;
    std::cout << std::endl;

    //TEST 2 - ADD HORIZONTAL TILES
    playerTile = player->getMosaic()->getGridTile(0, 3);
    delete playerTile;
    playerTile = new Tile(YELLOW);

    playerTile = player->getMosaic()->getGridTile(0, 2);
    delete playerTile;
    playerTile = new Tile(YELLOW);

    std::cout << "Printing Player Mosaic: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    playerScore = gameEngine->calculatePlayerScores(player);
    std::cout << "Expected Score = 3 - Actual = " << playerScore << std::endl;
    std::cout << std::endl;

    //TEST 2 - ADD VERTICAL TILES
    //Clear previous horizontal tiles
    playerTile = player->getMosaic()->getGridTile(0, 3);
    delete playerTile;
    playerTile = new Tile(NO_TILE);

    playerTile = player->getMosaic()->getGridTile(0, 2);
    delete playerTile;
    playerTile = new Tile(NO_TILE);

    //Add vertical tiles
    playerTile = player->getMosaic()->getGridTile(1, 4);
    delete playerTile;
    playerTile = new Tile(RED);

    playerTile = player->getMosaic()->getGridTile(2, 4);
    delete playerTile;
    playerTile = new Tile(RED);

    std::cout << "Printing Player Mosaic: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    playerScore = gameEngine->calculatePlayerScores(player);
    std::cout << "Expected Score = 3 - Actual = " << playerScore << std::endl;
    std::cout << std::endl;

    //TEST 2 - CROSS
    //Clear previous horizontal tiles
    playerTile = player->getMosaic()->getGridTile(0, 3);
    delete playerTile;
    playerTile = new Tile(RED);

    playerTile = player->getMosaic()->getGridTile(0, 2);
    delete playerTile;
    playerTile = new Tile(RED);

    std::cout << "Printing Player Mosaic: " << std::endl;
    gameEngine->printPlayerMosaic(player);

    playerScore = gameEngine->calculatePlayerScores(player);
    std::cout << "Expected Score = 6 - Actual = " << playerScore << std::endl;
    std::cout << std::endl;

    delete gameEngine;
}

void testMosaicClass() {
    Mosaic* m = new Mosaic();

    std::cout << "Printing Grid" << std::endl;
    for(int i = 0; i < ROWS; ++i) {

        for(int j = 0; j < COLS; ++j) {
            std::cout << m->getPatternLineRow(i)[j]->getCharColour() << " ";
        }

        std::cout << "|| ";

        for(int j = 0; j < COLS; ++j) {
            std::cout << m->getGridTile(i, j)->getCharColour() << " ";
        }

        std::cout << std::endl;
    }

    delete m;
}

void testFactoriesClass() {
    //Create fixed tile bag
    TileBag* tileBag = new TileBag();
    tileBag->generateFixedTileBag();

    Factories* factories = new Factories();
    factories->FillFactoriesFromTileBag(tileBag);

    std::cout << "Expected Factory Sizes: 0 4 4 4 4 4 - Actual: ";
    for(int i = 0; i < 6; ++i) {
        std::cout << factories->getFactory(i)->size() << " ";
    }
    std::cout << std::endl;

    std::cout << "Print Factories: " << std::endl;
    for(int i = 0; i < 6; ++i) {
        Factory* current = factories->getFactory(i);

        std::cout << i << ": ";
        for(int j = 0; j < current->size(); ++j) {
            std::cout << current->getTileAt(j)->getCharColour() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
 
    delete factories;
}

void testFactoryClass() {
    Factory* factory = new Factory(0);
    std::cout << "Expected Factory Number (0) - Actual: " << factory->getFactoryNumber() << std::endl;
    
    factory->addTile(new Tile(BLACK));
    factory->addTile(new Tile(BLACK));
    factory->addTile(new Tile(YELLOW));
    factory->addTile(new Tile(RED));

    std::cout << "Expected Factory Tiles (UUYR) - Actual: ";
    for(int i = 0; i < 4; ++i) {
        std::cout << factory->getTileAt(i)->getCharColour();
    }
    std::cout << std::endl;

    std::cout << "Expected Size (4) - Actual: " << factory->size() << std::endl;

    int yellowTile = factory->getIndexOfSameColourTile(YELLOW);
    std::cout << "GetYellowTilePosition (2) - Actual: " << yellowTile << std::endl;
    
    factory->removeTileAt(yellowTile);
    std::cout << "Removed Yellow - Expected (UUR) - Actual: ";
    for(int i = 0; i < 3; ++i) {
        std::cout << factory->getTileAt(i)->getCharColour();
    }
    std::cout << std::endl;

    factory->clear();
    std::cout << "Clear - Expected Length (0) - Actual: " << factory->size() << std::endl;

    delete factory;
}

void testTileBagClass() {
    TileBag* tileBag = new TileBag();

    std::cout << "Fixed Tile Bag: ";
    tileBag->generateFixedTileBag();
    for(int i = 0; i < tileBag->getLength(); ++i) {
        std::cout << tileBag->get(i)->getCharColour();
    }
    std::cout << std::endl;

    std::cout << "Expected Length (100) - Actual: " << tileBag->getLength() << std::endl;

    std::cout << "Draw from Front: Expected (R) - Actual: " << tileBag->drawTile()->getCharColour() << std::endl;

    std::cout << "Remove All Tiles: Actual - ";
    for(int i = 0; i < 100; ++i) {
        tileBag->removeTile();
    }
     
    //Display contents of TileBag
    for(int i = 0; i < tileBag->getLength(); ++i) {
        std::cout << tileBag->get(i)->getCharColour();
    }
    std::cout << std::endl;

    std::cout << "Expected Length (0) - Actual: " << tileBag->getLength() << std::endl;

    delete tileBag;
}

void testTileClass() {
    Tile* tile = new Tile(BLACK);
    std::cout << "Expected Colour (4)  - Actual:  " << tile->getColour() << std::endl;
    std::cout << "Expected Colour (U)  - Actual:  " << tile->getCharColour() << std::endl;

    delete tile; 
}

void testUtilsClass() {
    std::cout << "Expected Red (0) - Actual: " << convertCharToColour('R') << std::endl;
    std::cout << "Expected YELLLOW (1) - Actual: " << convertCharToColour('Y') << std::endl;
    std::cout << "Expected DARK_BLUE (2) - Actual: " << convertCharToColour('B') << std::endl;
    std::cout << "Expected LIGHT_BLUE (3) - Actual: " << convertCharToColour('L') << std::endl;
    std::cout << "Expected BLACK (4) - Actual: " << convertCharToColour('U') << std::endl;
    std::cout << "Expected FIRST_PLAYER (5) - Actual: " << convertCharToColour('F') << std::endl;
    std::cout << "Expected NO_TILE (6) - Actual: " << convertCharToColour('.') << std::endl;
}
