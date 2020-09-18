#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "tileBag.h"
#include "factories.h"
// #include "player.h"

#define TOTAL_PLAYERS 2


class GameEngine {
public:
    GameEngine();
    GameEngine(const GameEngine& other);
    GameEngine(GameEngine&& other);
    ~GameEngine();

    void runGame();

    void addTileFromFactoryToMosaic(); 

    // void printPlayerMosaic(Player* player);

    // int calculatePlayerScores(Player* player);

    // void addTilesToMosaicFromPatternLine(Player* player);

private:
    TileBag tileBag;
    Factories factories;
    // Player* players[TOTAL_PLAYERS];
};

#endif //GAME_ENGINE_H