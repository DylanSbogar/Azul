#include "factories.h"

Factories::Factories() {
    centreFactory = new Factory(0);

    for(int i = 1; i < NUMBER_OF_FACTORIES; i++) {
        allFactories[i] = new Factory(i);
    }

}

Factories::~Factories() {
    delete centreFactory;
    centreFactory = nullptr;

    for(int i = 1; i < NUMBER_OF_FACTORIES; i++) {
        if(allFactories[i] != nullptr) {
            delete allFactories[i];
             allFactories[i] = nullptr;
        }
    }
}

Factory* Factories::getFactory(int FactoryNumber) {
    return allFactories[FactoryNumber];
}
