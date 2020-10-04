#ifndef UTILS_H
#define UTILS_H

#include "tile.h"

//INPUT: Valid char colour: 
//Useful for reading char input and extracting Colour which can be used to create Tile objects
//NOTE: Invalid char returns BLANK Colour
Colour convertCharToColour(char colour);

#endif //UTILS_H