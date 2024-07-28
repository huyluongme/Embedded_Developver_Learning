#ifndef FISH_H
#define FISH_H

#include "pet.h"

class Fish : public Pet
{
private:
    string m_waterType;
public:
    Fish(string type, string name, string habitat, Gender gender, string waterType);
    ~Fish();
    
    string  move() const override;
    string  feed() const override;
    string  makeSound() const override;

    string  getWaterType();
    string  getInfor();

    void    setWaterType(string newWaterType);
};

#endif