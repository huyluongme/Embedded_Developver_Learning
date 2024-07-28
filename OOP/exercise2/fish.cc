#include "fish.h"

Fish::Fish(string type, string name, string habitat, Gender gender, string waterType)
    : Pet(type, name, habitat, gender), m_waterType(waterType)
{
}
    
Fish::~Fish()
{
}

string Fish::move() const
{
    return this->getName() + " is swimming";
}

string Fish::feed() const
{
    return this->getName() + " is being fed by fish food";
}

string Fish::makeSound() const
{
    return this->getName() + " has no sound";
}

string Fish::getWaterType()
{
    return this->m_waterType;
}

string Fish::getInfor()
{
    string infor = Pet::getInfor();
    infor += "\n - Water type: " + this->getWaterType();
    return infor;
}

void Fish::setWaterType(string newWaterType)
{
    this->m_waterType = newWaterType;
}