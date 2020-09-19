#include "player.h"

    player::player(std::string playerName){
        this->playerName = playerName;
        playerMosaic = new mosaic();

    }
    player::~player(){


    }

    std::string player::getPlayerName(){
        return this->playerName;

    }

    int player::getPlayerScore(){
        return this->score;

    }

    void player::setPlayerScore(int score){
        this->score = score;

    }

    mosaic* player::getMosaic(){
        return playerMosaic;

    }