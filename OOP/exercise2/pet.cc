#include "pet.h"

Pet::Pet(string type, string name, string habitat, Gender gender)
    : m_type(type), m_name(name), m_habitat(habitat), m_gender(gender)
{
}

Pet::~Pet()
{
}

string Pet::getType() const
{
    return this->m_type;
}

string Pet::getName() const
{
    return this->m_name;
}

string Pet::getHabitat() const
{
    return this->m_habitat;
}

string Pet::getGender() const
{
    string gender;
    if(this->m_gender == Gender::Male) gender = "Male";
    else gender = "Female";
    return gender;
}

string Pet::getInfor() const
{
    string infor = "Information:\n - Type: " + this->getType();
    infor += "\n - Name: " + this->getName();
    infor += "\n - Gender: " + this->getGender();
    infor += "\n - Habitat: " + this->getHabitat();
    return infor;
}

void Pet::setType(string newType)
{
    this->m_type = newType;
}

void Pet::setName(string newName)
{
    this->m_name = newName;
}

void Pet::setHabitat(string newHabitat)
{
    this->m_habitat = newHabitat;
}

void Pet::setGender(Gender newGender)
{
    this->m_gender = newGender;
}