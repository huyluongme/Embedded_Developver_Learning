#include "number_factory.h"
#include "hex_number.h"
#include "oct_number.h"
#include "dec_number.h"

NumberFactory::NumberFactory(/* args */)
{
}

NumberFactory::~NumberFactory()
{
}

Number* NumberFactory::createNumber(NumberType type, int value)
{
    if(type == NumberType::HEX)
    {
        return new HexNumber(value);
    }
    else if(type == NumberType::OCT)
    {
        return new OctNumber(value);
    }
    else
    {
        return new DecNumber(value);
    }
}