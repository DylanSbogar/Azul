#include "player.h"
    //Constructor
    Player::Player(std::string playerName){
        this->playerName = playerName;
        playerMosaic = new Mosaic();
        score = 0;
    }
    
    //Deconstructor
    Player::~Player(){
    }

    //Returns player's name
    std::string Player::getPlayerName(){
        return this->playerName;
    }

    //Returns player's score
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
