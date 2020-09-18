#ifndef UTILS_H
#define UTILS_H

#include "tile.h"

//Useful for reading char input and extracting Colour which can be used to create Tile objects
//NOTE: Invalid char returns NO_TILE Colour
Colour convertCharToColour(char colour);

#endif //UTILS_H