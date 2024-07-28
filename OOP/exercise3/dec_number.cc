#include "dec_number.h"

DecNumber::DecNumber(int value)
    : Number(value)
{
}

DecNumber::~DecNumber()
{
}

void DecNumber::print_it() const
{
    cout << value;
}