// initialization.h
//
// Uniform initialization of the simulation of ants walking on a table, subdivided into
// squares. Header file.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#ifndef INITIALIZATIONH
#define INITIALIZATIONH

#include <rarray>

// The function initialize_uniform assigns a number to each element in a
// two-dimensional array such that those numbers add up to a given total, 
// in as uniform a way possible.
//
// Parameters:
//  number    an 2d rarray of ints (by reference) 
//  total     the amount that all numbers in the array must sum up to.
// 
void initialize_uniform(rarray<int,2>& number, int total);
                     
#endif
