#include "pet_factory.h"
#include "dog.h"
#include "fish.h"

PetFactory::PetFactory() {};

PetFactory::~PetFactory() {};

Dog* PetFactory::createDog(string type, string name, string habitat, Gender gender, int trainingLevel, string favoriteToy)
{
    return new Dog(type, name, habitat, gender, trainingLevel, favoriteToy);
}

Fish* PetFactory::createFish(string type, string name, string habitat, Gender gender, string waterType)
{
    return new Fish(type, name, habitat, gender, waterType);
}