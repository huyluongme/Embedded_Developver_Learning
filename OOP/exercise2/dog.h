#ifndef DOG_H
#define DOG_H

#include "pet.h"

class Dog : public Pet
{
private:
    int m_trainingLevel;
    string m_favoriteToy;

public:
    Dog(string type, string name, string habitat, Gender gender, int trainingLevel, string favoriteToy);
    ~Dog();

    string  move() const override;
    string  feed() const override;
    string  makeSound() const override;

    string  getTrainingLevel();
    string  getFavoriteToy();
    string  getInfor();

    void    setTrainingLevel(int newTrainingLevel);
    void    setFavoriteToy(string newFavoriteToy);
};

#endif