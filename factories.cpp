#include "factories.h"
#include <utility>

Factories::Factories() {
    centreFactory = new Factory(0);
    allFactories[0] = centreFactory;

    for(int i = 1; i < NUMBER_OF_FACTORIES; i++) {
        allFactories[i] = new Factory(i);
    }
}

Factories::Factories(const Factories& other) {
    centreFactory = new Factory(*other.centreFactory);
    for(int i = 0; i < NUMBER_OF_FACTORIES; ++i) {
        allFactories[i] = new Factory(*other.allFactories[i]); 
    }
}

Factories::Factories(Factories&& other) {
    centreFactory = new Factory(std::move(*other.centreFactory));
    for(int i = 0; i < NUMBER_OF_FACTORIES; ++i) {
        allFactories[i] = new Factory(std::move(*other.allFactories[i])); 
    }
}

Factories::~Factories() {
    //Iterate through allFactories array and delete each Factory
    //Since centreFactory is within the array, don't need to explicitly delete it 
    for(int i = 0; i < NUMBER_OF_FACTORIES; i++) {
        if(allFactories[i] != nullptr) {
            delete allFactories[i];
            allFactories[i] = nullptr;
        }
    }
}

Factory* Factories::getFactory(int FactoryNumber) {
    return allFactories[FactoryNumber];
}

void Factories::FillFactoriesFromTileBag(TileBag* tilebag) {
    //Loop starts filling factories from factory 1
    for(int i = 1; i < NUMBER_OF_FACTORIES; i++) {

        //Add FACTORY_SIZE tiles in each factory
        for(int j = 0; j < FACTORY_SIZE; ++j) {
            
            //Check if tile is returned
            Tile* tile = tilebag->drawTile();
            if(tile != nullptr) {
                //Add Tile to Factory
                allFactories[i]->addTile(tile);

                //Remove added tile from the tile bag
                tilebag->removeTile();
            }
        }
    }
}
