// initialization.cc
//
// Uniform initialization of the simulation of ants walking on a table, subdivided into
// squares. 
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "initialization.h"

void initialize_uniform(rarray<int,2>& number, int total)
{
    // place the ants evenly on the table
    int n = 0; // linear index
    for (int i = 0; i < number.extent(0); i++) {
        for (int j = 0; j < number.extent(1); j++) {            
            number[i][j] = ((long long)(n+1)*total)/number.size() - ((long long)(n)*total)/number.size();
            n++;
        }
    }    
}
                     
