#include "player.h"

    Player::Player(std::string playerName){
        this->playerName = playerName;
        playerMosaic = new Mosaic();
        score = 0;
    }
    
    Player::~Player(){

    }

 //returns player's name
    std::string Player::getPlayerName(){
        return this->playerName;
    }

 //returns player's score
    int Player::getPlayerScore(){
        return this->score;
    }

 //INPUT: integer of the end of round score
 //adds end of round score with total score
    void Player::setPlayerScore(int score) {
        this->score += score;
    }
 //OUTPUT: returns player's mosaic
    Mosaic* Player::getMosaic(){
        return playerMosaic;
    }
