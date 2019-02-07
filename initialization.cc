// initialization.cc
//
// Uniform initialization of the simulation of ants walking on a table, subdivided into
// squares. 
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "initialization.h"

void initialize_uniform(int* number, int length, int total)
{
    // place the ants evenly on the table
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            int n = i*length + j; // linear index
            number[n] = ((long long)(n+1)*total)/(length*length) - ((long long)(n)*total)/(length*length);
        }
    }    
}
                     
