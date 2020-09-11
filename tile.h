#ifndef TILE_H
#define TILE_H

enum Colour {
    RED,
    YELLOW,
    DARK_BLUE,
    LIGHT_BLUE,
    BLACK,
    FIRST_PLAYER,
    NO_TILE,
};

class Tile {
public: 
    Tile(Colour colour);
    Tile(Tile& other);
    ~Tile();

    Colour getColour();
    char getCharColour();

private: 
    char convertColourToChar(Colour colour);
    
    Colour colour;
    char charColour;
};

#endif //TILE_H