#include "dog_factory.h"

DogFactory::DogFactory(int trainingLevel, string favoriteToy) 
    : m_trainingLevel(trainingLevel), m_favoriteToy(favoriteToy) {}

DogFactory::~DogFactory() {}

Pet* DogFactory::createPet(string type, string name, string habitat, Gender gender) 
{
    return new Dog(type, name, habitat, gender, m_trainingLevel, m_favoriteToy);
}