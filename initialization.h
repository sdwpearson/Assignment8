// initialization.h
//
// Uniform initialization of the simulation of ants walking on a table, subdivided into
// squares. Header file.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#ifndef INITIALIZATIONH
#define INITIALIZATIONH

// The function initialize_uniform assigns a number to each element in the 
// length x length array such that those numbers add up to a given total, 
// in as uniform a way possible.
//
// Parameters:
//  number    a pointer to the first element of the length x length array of ints
//  length    the size of each dimension of the array
//  total     the amount that all numbers in the array must sum up to.
// 
void initialize_uniform(int* number, int length, int total);
                     
#endif
