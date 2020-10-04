#include "utils.h"

Colour convertCharToColour(char colour) {
    char red = 'R';
    char yellow = 'Y';
    char dark_blue = 'B';
    char light_blue = 'L';
    char black = 'U';
    char first_player = 'F';
    char no_tile = '.';

    Colour tile = BLANK;

    //Check if char matches char values and convert to corresponding colour
    if(colour == red) {
        tile = RED;
    } else if(colour == yellow) {
        tile = YELLOW;
    } else if(colour == dark_blue) {
        tile = DARK_BLUE;
    } else if(colour == light_blue) {
        tile = LIGHT_BLUE;
    } else if(colour == black) {
        tile = BLACK;
    } else if(colour == first_player) {
        tile = FIRST_PLAYER;
    } else if(colour == no_tile) {
        tile = NO_TILE;
    }
    return tile;
}
