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
    ~Factory();

    //INPUT: Tile shouldn't be nullptr
    //OUTPUT: Adds Tile to the back of the factory vector
    //NOTE: ensure that factories doesn't exceed limit of 'INITIAL_FACTORY_SIZE' tiles
    //      aside from centre Factory
    void addTile(Tile* tile);

    //OUTPUT: Removes tile pointer from factory at given index and returns true.
    //        Otherwise, method will simply return false.
    //NOTE: Method assumes that tile has another pointer to it (otherwise memory leak will occur!)
    bool removeTileAt(int index);

    //OUTPUT: Returns the size of the factory
    int size();

    //OUTPUT: Returns index of rightmost tile of given colour
    //NOTE: Returns INVALID_INDEX if Colour is not present in factory 
    int getIndexOfSameColourTile(Colour colour);

    //OUTPUT: Clears the factory vector
    void clear();

    //OUTPUT: returns factory number ID
    //NOTE: This should be unique for each factory
    int getFactoryNumber();

    //INPUT: index > 0 and index < factory size
    //OUTPUT: Returns tile at given index
    Tile* getTileAt(int index);

private: 
    int factoryNumber;
    vector<Tile*> factoryTiles;

};

#endif //FACTORY_H