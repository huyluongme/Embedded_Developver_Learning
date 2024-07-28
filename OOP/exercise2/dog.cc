#include "dog.h"

Dog::Dog(string type, string name, string habitat, Gender gender, int trainingLevel, string favoriteToy)
    : Pet(type, name, habitat, gender), m_trainingLevel(trainingLevel), m_favoriteToy(favoriteToy)
{
}

Dog::~Dog()
{
}

string Dog::move() const
{
    return this->getName() + " is walking";
}

string Dog::feed() const
{
    return this->getName() + " is being fed by dog food";
}

string Dog::makeSound() const
{
    return this->getName() + " saying: Woof woof";
}

string Dog::getTrainingLevel()
{
    return std::to_string(this->m_trainingLevel);
}

string Dog::getFavoriteToy()
{
    return this->m_favoriteToy;
}

string Dog::getInfor()
{
    string infor = Pet::getInfor();
    infor += "\n - Training level: " + this->getTrainingLevel();
    infor += "\n - Favorite toy: " + this->getFavoriteToy();
    return infor; 
}

void Dog::setTrainingLevel(int newTrainingLevel)
{
    this->m_trainingLevel = newTrainingLevel;
}

void Dog::setFavoriteToy(string newFavoriteToy)
{
    this->m_favoriteToy = newFavoriteToy;
}