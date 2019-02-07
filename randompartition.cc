// randompartition.cc
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include <random>
#include <algorithm>
#include "randompartition.h"

// Implementation of the function to randomly divide a number 'total'
// into a set of 'numdivision' numbers that add up to 'total'. Uses
// c++11 random library to generate the randomness.
void rand_partition(int total, int nparts, int* nperpart, size_t seed)
{
    // never mind the implementation, we'll see how this works in a future lecture.
    static std::mt19937 engine(seed);
    std::uniform_int_distribution<int> uniformint(0, total);

    nperpart[0] = 0;
    for (int k = 1; k < nparts; k++)
        nperpart[k] = uniformint(engine);

    std::sort(nperpart, nperpart + nparts);

    for (int k = 0; k < nparts-1; k++)
        nperpart[k] = nperpart[k+1] - nperpart[k];
    
    nperpart[nparts-1] = total - nperpart[nparts-1]; 
}

