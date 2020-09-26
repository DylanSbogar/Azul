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
    Factory(const Factory& other);
    Factory(Factory&& other);
    ~Factory();

    //Adds Tile to the back of the list
    void addTile(Tile* tile);

    //Removes tile pointer from factory at given index
    //Returns true if tile was removed successfully
    //NOTE: Method assumes that tile has another pointer to it (or else memory leak will occur!)
    bool removeTileAt(int index);

    //Returns the size of the factory
    int size();

    //Returns index of rightmost tile of given colour
    //NOTE: Returns INVALID_INDEX if Colour is not present in factory 
    int getIndexOfSameColourTile(Colour colour);

    //Clears the factory vector
    void clear();

    //returns factory number
    int getFactoryNumber();

    //INPUT: index > 0 and index < factory size
    //OUTPUT: tile at given index
    Tile* getTileAt(int index);

private: 
    int factoryNumber;
    vector<Tile*> factoryTiles;

};

#endif //FACTORY_H