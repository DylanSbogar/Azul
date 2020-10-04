#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include <iterator>
#include <vector>

#include "tileBag.h"
#include "factories.h"
#include "player.h"
#include "utils.h"
#include "load.h"

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::ofstream;
using std::vector;

#define TOTAL_PLAYERS 2

class GameEngine {
public:
    GameEngine();
    GameEngine(const GameEngine& other);
    ~GameEngine();

    //Initialize loading game
    void initialiseGame(Load* load);

    //Initialise terminal game
    void initialiseGame();

private:
    //Runs the main game loop
    void runGame();

    //Transfers tiles from factory to mosaic
    //OUTPUT: returns true valid input was given
    bool addTileFromFactoryToMosaic(Player* currentPlayer, int factoryNumber, char colour, int pattRow); 

    //Displays player mosaic
    void printPlayerMosaic(Player* player);

    //calculates player scores
    int calculatePlayerScores(Player* player);

    //saves current game
    void saveGame(string fileName);

    //Loads player turns from vector
    bool playerEntersTurn(Player* currentPlayer, string function, string param1, string param2, string param3);

    //Gets user input and adds to turns vector
    //Returns true is player enters a turn input 
    bool playerEntersTurn(Player* currentPlayer);

    //Generates players at the start of the game.
    void createPlayers(string player1Name, string player2Name);

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

// private:
    TileBag* tileBag;
    Factories* factories;
    Player* players[TOTAL_PLAYERS];
    vector<string> turns;
    Load* load;
};

#endif //GAME_ENGINE_H