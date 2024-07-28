#include "hex_number.h"

HexNumber::HexNumber(int value)
    : Number(value)
{
}

HexNumber::~HexNumber()
{
}

void HexNumber::print_it() const
{
    int tmpVal = abs(this->value);
    std::string hex = "";
    if(tmpVal == 0)
    {
        hex = "0";
    }
    else
    {
        const char hexDigits[] = "0123456789ABCDEF";
        while (tmpVal > 0) {
            // takes the last 4 bits of tmpVal (4bits = 1 hex digit)
            int remainder = tmpVal & 0xF; // 0xF = 15 (decimal)
            // get the corresponding from hexDigits and add to hex string;
            hex = hexDigits[remainder] + hex; 
            //shift tmpVal to right 4 bits, prepare for the next iteration
            tmpVal >>= 4;
            // for ex: 255 
            // 255 => 1111 1111 (binary)
            // Iteration 1: remainder is 15 (1111) => F in hexDigit => hex = "F" => tmpVal = 15
            // Iteration 2: remainder is 15 (1111) => F in hexDigit => hex = "FF" => tmpVal = 0
            // 255 => 0xFF
        }
    }
    if (this->value < 0) {
        std::cout << "-0x" << hex;
    } else {
        std::cout << "0x" << hex;
    }
}