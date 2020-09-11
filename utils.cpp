#include "utils.h"

Colour convertCharToColour(char colour) {
    char red = 'R';
    char yellow = 'Y';
    char dark_blue = 'B';
    char light_blue = 'L';
    char black = 'U';
    char first_player = 'F';

    Colour tile = NO_TILE;

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
    }

    return tile;
}
