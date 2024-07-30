#ifndef DOG_FACTORY_H
#define DOG_FACTORY_H

#include "pet_factory.h"

class DogFactory : public PetFactory
{
private:
    int m_trainingLevel;
    string m_favoriteToy;
public:
    DogFactory(int trainingLevel, string favoriteToy);
    ~DogFactory();

    Pet* createPet(string type, string name, string habitat, Gender gender) override;
};

#endif