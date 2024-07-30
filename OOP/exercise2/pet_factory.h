#ifndef PET_FACTORY_H
#define PET_FACTORY_H

#include "dog.h"
#include "fish.h"

class PetFactory
{
public:
    virtual Pet* createPet(string type, string name, string habitat, Gender gender) = 0;
};

#endif