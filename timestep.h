// timestep.h
//
// Summarize and reports ants on a table.  Header file
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#ifndef TIMESTEPH
#define TIMESTEPH

#include <cstddef> // for size_t

// Function that performs one time step, in which each 
// ants has a chance to move to a neighboring square or 
// fall off the table.
//
// Parameters:
//   number_of_ants       pointer to the first element of the 2d array with the current number of ants (in/out)
//   new_number_of_ants   pointer to the first element of an auxialiar array to same size of number_of_ants (temp)
//   length               the size of both dimensions of thee array
//   seed                 the random seed by which to initialize the random numbers. Only used the first time the function is called.
//
void perform_one_timestep(int* number_of_ants, int* new_number_of_ants, int length, size_t seed);

#endif
