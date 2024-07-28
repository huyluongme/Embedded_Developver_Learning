#ifndef PET_FACTORY_H
#define PET_FACTORY_H

#include "dog.h"
#include "fish.h"

class PetFactory
{
public:
    PetFactory(/* args */);
    ~PetFactory();

    Dog* createDog(string type, string name, string habitat, Gender gender, int trainingLevel, string favoriteToy);
    Fish* createFish(string type, string  name, string hanitat, Gender gender, string waterType);
};

#endif