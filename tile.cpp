#include "tile.h"

Tile::Tile(Colour colour) {
    this->colour = colour;
    this->charColour = convertColourToChar(colour);
}

Tile::Tile(const Tile& other) :
    colour(other.colour),
    charColour(other.charColour)
{
}

Tile::~Tile() 
{   
}

Colour Tile::getColour() {
    return colour;
}

char Tile::getCharColour() {
    return charColour;
}

char Tile::convertColourToChar(Colour colour) {
    char red = 'R';
    char yellow = 'Y';
    char dark_blue = 'B';
    char light_blue = 'L';
    char black = 'U';
    char first_player = 'F';
    char no_tile = '.';
    char blank = ' ';

    char tile = blank;

    if(colour == RED) {
        tile = red;
    } else if(colour == YELLOW) {
        tile = yellow;
    } else if(colour == DARK_BLUE) {
        tile = dark_blue;
    } else if(colour == LIGHT_BLUE) {
        tile = light_blue;
    } else if(colour == BLACK) {
        tile = black;
    } else if(colour == FIRST_PLAYER) {
        tile = first_player;
    } else if(colour == NO_TILE) {
        tile = no_tile;
    }
    return tile;
}