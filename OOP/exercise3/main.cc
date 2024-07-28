#include <iostream>

using namespace std;

#include "number_factory.h"

int main()
{
    NumberFactory* numberFactory = new NumberFactory();
    int value;
    cout << "Enter value: ";
    cin >> value;

    Number* hex = numberFactory->createNumber(NumberType::HEX, value);
    Number* oct = numberFactory->createNumber(NumberType::OCT, value);
    Number* dec = numberFactory->createNumber(NumberType::DEC, value);
    
    cout << "Hexadecimal: ";    
    hex->print_it();
    
    cout << "\nOctal: ";
    oct->print_it();

    cout << "\nDecimal: ";
    dec->print_it();

    delete hex;
    delete oct;
    delete dec;
    delete numberFactory;
    return 0;
}