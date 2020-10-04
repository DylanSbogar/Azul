#ifndef LOAD_H
#define LOAD_H

#include <iostream>
#include <vector>
#include <fstream>

using std::string;
using std::ifstream;
using std::endl;
using std::cin;
using std::cout;
using std::vector;

/*Global variables that let the game engine know whether
Azul is either loading a game or in the testing mode. They
are both set to true in their respective loadGame and testingMode
methods, and are set to false once loading has concluded.*/
extern bool isLoading;
extern bool isTesting;

class Load {
public:
    //Constructor
    Load(string fileName);
    
    //Deconstructor
    ~Load();

    /*First checks if the save file is valid, if true
    then it will read the file line-by-line, variables
    to the load object*/
    void loadGame(std::string fileName);

    //Calls loadGame() and sets global var isTesting to true
    void testingMode(std::string fileName);

    //Returns a string of the current turn to be input
    string getCurrentTurn();

    //Increments the turn counter after each turn has been loaded
    void incrementTurn();

    //Returns the total size of the turns vector
    int getTurnsSize();

    //Returns the current index of the turn vector that is being loaded
    int getCurrentTurnIndex();

    /*All methods below return a value based off of reading each line
    of the save file, and are used to set player names and tileBags.*/

    //Returns a string of the tileBag being loaded
    string getTileBag();

    //Returns a string of player 1's name being loaded
    string getPlayer1();

    //Returns a string of player 2's name being loaded
    string getPlayer2();
    
private:
    string fileName;

    string initTileBag;

    string player1Name;

    string player2Name;

    vector<string> turns;

    int index;
};

#endif //LOAD_H