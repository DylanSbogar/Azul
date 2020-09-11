#include "factory.h"

Factory::Factory(int factoryNumber) {
    this->factoryNumber = factoryNumber;
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

    if(factoryTiles.size() > 0 && index >=0 && index < length) {
        delete factoryTiles[index];
        factoryTiles[index] = nullptr;

        for(int i = index; i < length; ++i) {
            if(i <= length - 2) {
                factoryTiles[i] = factoryTiles[i+1];
            }
        }

        factoryTiles.pop_back();
        tileRemoved = true;
    }

    return tileRemoved;
}

int Factory::size() {
    return factoryTiles.size();
}

int Factory::getIndexOfSameColourTile(Colour colour) {
    int index = INVALID_INDEX;
    for(int i = 0; i < (signed int) factoryTiles.size(); ++i) {
        if(factoryTiles[i]->getColour() == colour) {
            index = i;
        }
    }

    return index;
 }


void Factory::clear() {
    for(int i = 0; i < (signed int) factoryTiles.size(); ++i) {
        delete factoryTiles[i];
        factoryTiles[i] = nullptr;
    }
    factoryTiles.clear();
}

int Factory::getFactoryNumber() {
    return factoryNumber;
}

//TESTING METHODS
// Tile* Factory::getTileAt(int index) {
//     return factoryTiles[index];
// }

