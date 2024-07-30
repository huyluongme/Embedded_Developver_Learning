#include <iostream>

using namespace std;

#include "dog.h"
#include "fish.h"
#include "pet_factory.h"
#include "dog_factory.h"
#include "fish_factory.h"

int main()
{
    
    // PetFactory* petFactory = new PetFactory();
    PetFactory* dogFactory = new DogFactory(1, "Bear");

    PetFactory* fishFactory = new FishFactory("Salt Water");

    // Dog
    Pet* pDog = dogFactory->createPet("Dog", "Billy", "Land", Gender::Male);
    cout << static_cast<Dog*>(pDog)->getInfor() << "\n\n";

    cout << "Dog's behavier:\n";
    cout << pDog->move() << '\n';
    cout << pDog->feed() << '\n';
    cout << pDog->makeSound() << "\n\n";
    
    static_cast<Dog*>(pDog)->setFavoriteToy("shoes");
    cout << "Information of dog after changed favorite toy\n";
    cout << static_cast<Dog*>(pDog)->getInfor() << "\n\n";
    delete pDog;

    //Fish
    Pet* pFish = fishFactory->createPet("Fish", "Nemo", "Aquatic", Gender::Female);
    cout << static_cast<Fish*>(pFish)->getInfor() << "\n\n";
    cout << "Fish's behavier:\n";
    cout << pFish->move() << '\n';
    cout << pFish->feed() << '\n';
    cout << pFish->makeSound() << "\n\n";

    static_cast<Fish*>(pFish)->setWaterType("Fresh water");
    cout << "Information of fish after changed water type\n";
    cout << static_cast<Fish*>(pFish)->getInfor() << '\n';
    delete pFish;

    delete dogFactory;
    delete fishFactory;

    return 0;
}