#ifndef OCT_NUMBER_H
#define OCT_NUMBER_H

#include "number.h"

class OctNumber : public Number
{
public:
    OctNumber(int value);

    void print_it() const override;

    ~OctNumber();
};

#endif