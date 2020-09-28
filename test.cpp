#include "gameEngine.h"
#include <iostream>
#include <string.h>
#include <fstream>

int main(void) {
    GameEngine* game = new GameEngine();

    //Should load the game and run it, reading from the input
    //Once input has been read, call runGame again to run from terminal

    //Load Game
    //Input file
    std::ifstream inFile;
    inFile.open("inFile.txt");

    //Output file
    std::string filename("debug.out");
    std::ofstream outFile;
    outFile.open(filename);

    game->runGame(&inFile, &outFile);

    //Close file:
    outFile.open(filename);
    inFile.close();



    //Run standard game after you've read from the file
    game->runGame(&std::cin, &std::cout);

    delete game;
}