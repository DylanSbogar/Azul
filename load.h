#ifndef LOAD_H
#define LOAD_H

#include <iostream>
#include "gameEngine.h"


using std::string;

class Load {
public:
    Load();
    Load(const Load& other);
    ~Load();

    void loadGame(std::string fileName);
    void testingMode(std::string fileName);

    TileBag* getTileBag();
    Player** getPlayers();
    vector<string> getTurns();
    
private:
    TileBag* initTileBag;
    Player* players[TOTAL_PLAYERS];
    vector<string> turns;
};

#endif //LOAD_H