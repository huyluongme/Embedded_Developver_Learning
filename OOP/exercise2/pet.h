#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>

using namespace std;

enum Gender
{
    Male,
    Female,
};

class Pet
{
private:
    string m_type, m_name, m_habitat;
    Gender m_gender;

public:
    Pet(string type, string name, string habitat, Gender gender);
    
    virtual string  move()          const = 0;
    virtual string  feed()          const = 0;
    virtual string  makeSound()     const = 0;

    string          getType()       const;
    string          getName()       const;
    string          getHabitat()    const;
    string          getGender()     const;
    string          getInfor()      const;

    void            setType(string newType);
    void            setName(string newName);
    void            setHabitat(string newHabitat);
    void            setGender(Gender newGender);

    ~Pet();
};

#endif