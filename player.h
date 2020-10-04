#ifndef PLAYER_H
#define PLAYER_H 

#include <iostream>
#include "mosaic.h"

class Player {
public:  

    Player(std::string playerName);
    ~Player();

    //returns player's name
    std::string getPlayerName();

    //returns player's name
    int getPlayerScore();


    //adds end of round score with total score
    void setPlayerScore(int score);

    //return player's mosaic 
    Mosaic* getMosaic();

private:

    std::string playerName;
    int score;
    Mosaic* playerMosaic; 

};


#endif //PLAYER_H