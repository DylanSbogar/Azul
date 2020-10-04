#ifndef UTILS_H
#define UTILS_H

#include "tile.h"

//INPUT: Valid char colour
//OUTPUT: Returns Colour enum corresponding to given char value
//NOTE: Invalid char returns 'BLANK' Colour
Colour convertCharToColour(char colour);

#endif //UTILS_H