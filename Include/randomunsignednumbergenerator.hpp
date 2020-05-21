#ifndef RANDOMNUMBERGENERATOR_HPP_INCLUDED
#define RANDOMNUMBERGENERATOR_HPP_INCLUDED
#include <random>

class RandomUnsignedNumberGenerator
{
    public:
        RandomUnsignedNumberGenerator();
        unsigned rollRandomUnsignedNumber(unsigned minnumber, unsigned maxnumber);
};


#endif // RANDOMNUMBERGENERATOR_HPP_INCLUDED
