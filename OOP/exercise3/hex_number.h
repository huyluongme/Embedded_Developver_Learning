#ifndef HEX_NUMBER_H
#define HEX_NUMBER_H

#include "number.h"

class HexNumber : public Number
{
public:
    HexNumber(int value);

    void print_it() const override;

    ~HexNumber();
};

#endif