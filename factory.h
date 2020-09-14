#ifndef FACTORY_H
#define FACTORY_H

#include "tile.h"
#include <vector>

#define INITIAL_FACTORY_SIZE 4
#define INVALID_INDEX -1

using std::vector;

class Factory {
public:
    Factory(int factoryNumber);
    ~Factory();

    //Adds Tile to the back of the array
    void addTile(Tile* tile);

    //Removes tile from given index, returns true if tile was removed successfully
    bool removeTileAt(int index);

    //Returns the size of the factory vector
    int size();

    //Returns index of rightmost tile of given colour
    //returns INVALID_INDEX if no tiles of given colour are present 
    int getIndexOfSameColourTile(Colour colour);

    //Clears the factory vector
    void clear();

    //returns factory number
    int getFactoryNumber();

    //TESTING METHOD
    //Get a Tile at a specifc index 
    Tile* getTileAt(int index);

private: 
    int factoryNumber;
    vector<Tile*> factoryTiles;

};

#endif //FACTORY_H