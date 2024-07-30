#ifndef FISH_FACTORY_H
#define FISH_FACTORY_H

#include "pet_factory.h"

class FishFactory : public PetFactory
{
private:
    string m_waterType;
public:
    FishFactory(string waterType);
    ~FishFactory();

    Pet* createPet(string type, string name, string habitat, Gender gender) override;
};

#endif