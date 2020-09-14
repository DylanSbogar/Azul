#ifndef FACTORIES_H
#define FACTORIES_H

#include "factory.h"

#define NUMBER_OF_FACTORIES 6

class Factories {
public:
    Factories();
    ~Factories();

    //Returns factory corresponding to the factoryNumber 
    Factory* getFactory(int FactoryNumber);

private:
    Factory* centreFactory;
    Factory* allFactories[NUMBER_OF_FACTORIES];
};

#endif //FACTORIES_H