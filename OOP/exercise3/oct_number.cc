#include "oct_number.h"

OctNumber::OctNumber(int value)
    : Number(value)
{
}

OctNumber::~OctNumber()
{
}

void OctNumber::print_it() const
{
    int tmpVal = abs(this->value);
    std::string oct = "";
    if(tmpVal == 0)
    {
        oct = "0";
    }
    else
    {
        const char octDigits[] = "01234567";
        while (tmpVal > 0) {
            // takes the last 3 bits of tmpVal (3bits = 1 oct digit)
            int remainder = tmpVal & 0x7;
            // get the corresponding from octDigits and add to oct string;
            oct = octDigits[remainder] + oct; 
            //shift tmpVal to right 3 bits, prepare for the next iteration
            tmpVal >>= 3;
            // for ex: 255 
            // 255 => 1111 1111 (binary)
            // Iteration 1: remainder is 7 (111) => 7 in octDigits => oct = "7" => tmpVal = 31
            // Iteration 2: remainder is 7 (111) => 7 in octDigits => oct = "77" => tmpVal = 3
            // Iteration 3: remainder is 3 (11) => 3 in octDigits => oct = "377" => tmpVal = 0
            // 255 => 0o337
        }
    }
    if(this->value < 0)
        cout << "-0o" << oct;
    else
        cout << "0o" << oct;
}