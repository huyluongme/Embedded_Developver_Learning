#ifndef DEC_NUMBER_H
#define DEC_NUMBER_H

#include "number.h"

class DecNumber : public Number
{
public:
    DecNumber(int value);

    void print_it() const override;

    ~DecNumber();
};

#endif