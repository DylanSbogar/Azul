#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <vector>

#include "tileBag.h"
#include "factories.h"
#include "player.h"

using std::string;

#define TOTAL_PLAYERS 2


class GameEngine {
public:
    GameEngine();
    GameEngine(const GameEngine& other);
    GameEngine(GameEngine&& other);
    ~GameEngine();

    //Runs the main game loop
    void runGame();

private:
    //Transfers tiles from factory to mosaic
    //OUTPUT: returns true valid input was given
    bool addTileFromFactoryToMosaic(Player* currentPlayer, int factoryNumber, char colour, int pattRow); 

    //Displays player mosaic
    void printPlayerMosaic(Player* player);

    //calculates player scores
    int calculatePlayerScores(Player* player);

    //saves current game
    void saveGame(string fileName);

    //Gets user input and adds to turns vector
    //Returns true is player enters a turn input 
    bool playerEntersTurn(Player* currentPlayer);

    //Generates players at the start of the game.
    void createPlayers();

    //runs a single turn for given player 
    //Returns false to indicate game to exit 
    bool runTurn(Player* currentPlayer);

    //Prints factories
    void printFactories();

    ////transfers tiles from patternline to grid
    void addTilesToMosaicFromPatternLine(Player* currentPlayer);

    //Check if turn parameters are valid
    //Returns true if all inputs are valid
    bool validateTurnInput(Player* currentPlayer, int factoryNumber, char colour, int patternLineRow);


    TileBag* tileBag;
    Factories* factories;
    Player* players[TOTAL_PLAYERS];
    vector<string> turns;
};

#endif //GAME_ENGINE_H