#include "randomunsignednumbergenerator.hpp"

RandomUnsignedNumberGenerator::RandomUnsignedNumberGenerator() {};
unsigned RandomUnsignedNumberGenerator::rollRandomUnsignedNumber(unsigned minnumber, unsigned maxnumber)
{
    thread_local std::mt19937 rolledNumber{std::random_device{}()};
    std::uniform_int_distribution<std::mt19937::result_type> dist(minnumber, maxnumber);
    return dist(rolledNumber);

}
