//Listing 1.2(reciprocal.cpp)C++ source file—reciprocal.cpp

#include <cassert>
#include "reciprocal.hpp"
    
double reciprocal(int i)
{
    // I should be non-zero.
    assert(i != 0);
    return 1.0 / i;
}