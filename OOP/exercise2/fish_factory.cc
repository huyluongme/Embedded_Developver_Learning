#include "fish_factory.h"

FishFactory::FishFactory(string waterType) 
    : m_waterType(waterType) {}

FishFactory::~FishFactory() {}

Pet* FishFactory::createPet(string type, string name, string habitat, Gender gender) 
{
    return new Fish(type, name, habitat, gender, m_waterType);
}