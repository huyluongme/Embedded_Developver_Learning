#ifndef NUMBER_FACTORY_H
#define NUMBER_FACTORY_H

#include "number.h"

enum NumberType
{
    HEX,
    OCT,
    DEC,
};

class NumberFactory
{
public:
    NumberFactory(/* args */);
    ~NumberFactory();

    Number* createNumber(NumberType type, int value);
};

#endif