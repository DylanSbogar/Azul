#ifndef TILE_H
#define TILE_H

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
    //INPUT: Should be a valid colour enum
    //OUTPUT: Creates a valid tile
    Tile(Colour colour);
    Tile(const Tile& other);
    ~Tile();

    //OUTPUT: Returns enum type of colour
    Colour getColour();

    //OUTPUT: Returns char value of colour
    char getCharColour();

private: 
    //INPUT: Should input valid colour from Colour enum
    //OUTPUT: Converts enum colour to a char when Tile is instantiated
    //NOTE: If invalid colour given, tile defaults to BLANK tile.
    char convertColourToChar(Colour colour);
    
    Colour colour;
    char charColour;
};

#endif //TILE_H