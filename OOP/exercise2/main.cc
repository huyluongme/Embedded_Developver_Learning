#include <iostream>

using namespace std;

#include "pet_factory.h"

int main()
{
    PetFactory* petFactory = new PetFactory();

    // Dog
    Dog* pDog = petFactory->createDog("Dog", "Billy", "Land", Gender::Male, 1, "toy");
    cout << pDog->getInfor() << "\n\n";

    cout << "Dog's behavier:\n";
    cout << pDog->move() << '\n';
    cout << pDog->feed() << '\n';
    cout << pDog->makeSound() << "\n\n";
    
    pDog->setFavoriteToy("shoes");
    cout << "Information of dog after changed favorite toy\n";
    cout << pDog->getInfor() << "\n\n";
    delete pDog;

    //Fish
    Fish* pF = petFactory->createFish("Fish", "Nemo", "Aquatic", Gender::Female, "Salt water");
    cout << pF->getInfor() << "\n\n";
    cout << "Fish's behavier:\n";
    cout << pF->move() << '\n';
    cout << pF->feed() << '\n';
    cout << pF->makeSound() << "\n\n";

    pF->setWaterType("Fresh water");
    cout << "Information of fish after changed water type\n";
    cout << pF->getInfor() << '\n';
    delete pF;

    delete petFactory;

    return 0;
}