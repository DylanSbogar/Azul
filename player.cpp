#include "player.h"

    Player::Player(std::string playerName){
        this->playerName = playerName;
        playerMosaic = new Mosaic();

    }
    Player::~Player(){


    }

    std::string Player::getPlayerName(){
        return this->playerName;

    }

    int Player::getPlayerScore(){
        return this->score;

    }

    void Player::setPlayerScore(int score){
        this->score = score;

    }

    Mosaic* Player::getMosaic(){
        return playerMosaic;

    }
