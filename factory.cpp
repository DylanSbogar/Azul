#include "factory.h"
#include <utility>


Factory::Factory(int factoryNumber) {
    this->factoryNumber = factoryNumber;
}

Factory::Factory(const Factory& other) :
    factoryNumber(other.factoryNumber)
{
    for(int i = 0; i < (signed int) factoryTiles.size(); ++i) {
        factoryTiles.push_back(new Tile(*other.factoryTiles[i]));
    }
}

Factory::Factory(Factory&& other) :
    factoryNumber(other.factoryNumber)
{
    for(int i = 0; i < (signed int) factoryTiles.size(); ++i) {
        factoryTiles.push_back(new Tile(std::move(*other.factoryTiles[i])));
    }
}

Factory::~Factory() {
    clear();
}

void Factory::addTile(Tile* tile) {
    factoryTiles.push_back(tile);
}

bool Factory::removeTileAt(int index) {
    bool tileRemoved = false;
    signed int length = (signed int) factoryTiles.size();

    //Ensure index is within valid range
    if(factoryTiles.size() > 0 && index >=0 && index < length) {

        //Loose pointer since it is being moved
        factoryTiles[index] = nullptr;

        //Shift rest of the tiles to fill in deleted space
        for(int i = index; i < length; ++i) {
            if(i <= length - 2) {
                factoryTiles[i] = factoryTiles[i+1];
            }
        }

        //Remove last tile of list (which is a copy of tile at (length-2))
        factoryTiles.pop_back();
        
        tileRemoved = true;
    }

    return tileRemoved;
}

int Factory::size() {
    return factoryTiles.size();
}

int Factory::getIndexOfSameColourTile(Colour colour) {
    //Return INVALID_INDEX if colour not found in factory
    int index = INVALID_INDEX;

    //Iterate through vector, if tile matches colour, update index value
    for(int i = 0; i < (signed int) factoryTiles.size(); ++i) {
        if(factoryTiles[i]->getColour() == colour) {
            index = i;
        }
    }

    return index;
 }

void Factory::clear() {
    //Iterate through vector and delete all tiles
    for(int i = 0; i < (signed int) factoryTiles.size(); ++i) {
        delete factoryTiles[i];
        factoryTiles[i] = nullptr;
    }
    factoryTiles.clear();
}

int Factory::getFactoryNumber() {
    return factoryNumber;
}

Tile* Factory::getTileAt(int index) {
    return factoryTiles[index];
}