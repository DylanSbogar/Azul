#include "gameEngine.h"
#include <iostream>
#include <string.h>
#include <fstream>

int main(void) {
    GameEngine* game = new GameEngine();

    //Load Game
    //Read file:
    std::ifstream inFile;
    inFile.open("inFile.txt");

    //Output file
    std::string filename("debug.out");
    std::ofstream outFile;
    outFile.open(filename);


    // std::string filename = "/saves/test.save";
    // std::ifstream file(filename);
    // std::ifstream ifs ("test.txt", std::ifstream::in);

    game->runGame(&inFile, &outFile);

    //Close file:
    outFile.open(filename);
    inFile.close();



    //Run standard game
    game->runGame(&std::cin, &std::cout);

    delete game;
}