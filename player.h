#ifndef PLAYER_H
#define PLAYER_H 

#include <iostream>
#include "mosaic.h"

class player {
public:  

    player(std::string playerName);
    ~player();

    //returns player's name
    std::string getPlayerName();

    //returns player's name
    int getPlayerScore();

    //set player's score with new score
    void setPlayerScore(int score);

    //return player's mosaic 
    mosaic* getMosaic();

private:

    std::string playerName;
    int score;
    mosaic* playerMosaic; 

};


#endif //PLAYER_H