#ifndef FACTORIES_H
#define FACTORIES_H

#include "factory.h"
#include "tileBag.h"
#include <utility>

#define NUMBER_OF_FACTORIES 6
#define FACTORY_SIZE 4

class Factories {
public:
    Factories();
    Factories(const Factories& other);
    Factories(Factories&& other);
    ~Factories();

    //INPUT: Must be between 0 and (NUMBER_OF_FACTORIES - 1)
    //OUTPUT: returns pointer to factory corresponding to factory number
    Factory* getFactory(int FactoryNumber);

    //Fills factories from 1-5 (in order) from the given tile bag
    //NOTE: Ensure tile bag is not nullptr
    void FillFactoriesFromTileBag(TileBag* tilebag); 


    //Checks if all factories are empty
    bool allFactoriesAreEmpty();

private:
    Factory* centreFactory;
    Factory* allFactories[NUMBER_OF_FACTORIES];
};

#endif //FACTORIES_H