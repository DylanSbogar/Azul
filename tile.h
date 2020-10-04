#ifndef TILE_H
#define TILE_H

#include <utility>

//Includes the different tile types
enum Colour {
    RED,
    YELLOW,
    DARK_BLUE,
    LIGHT_BLUE,
    BLACK,
    FIRST_PLAYER,
    NO_TILE,
    BLANK,
};

class Tile {
public: 
    Tile(Colour colour);
    Tile(const Tile& other);
    Tile(Tile&& other);
    ~Tile();

    //Returns enum type of colour
    Colour getColour();

    //Returns char value of colour
    char getCharColour();

private: 
    //Converts enum colour to a char when Tile is instantiated
    char convertColourToChar(Colour colour);
    
    Colour colour;
    char charColour;
};

#endif //TILE_H