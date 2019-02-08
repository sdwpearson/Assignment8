// timestep.h
//
// Summarize and reports ants on a table.  Header file
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#ifndef TIMESTEPH
#define TIMESTEPH

#include <cstddef> // for size_t
#include <rarray>

// Function that performs one time step, in which each 
// ants has a chance to move to a neighboring square or 
// fall off the table.
//
// Parameters:
//   number_of_ants       the 2d rarray with the current number of ants (in/out)
//   new_number_of_ants   an auxialiary 2d rarray to same size of number_of_ants (temp, assumed preallocated)
//   seed                 the random seed by which to initialize the random numbers. Only used the first time the function is called.
//
void perform_one_timestep(rarray<int,2>& number_of_ants, rarray<int,2>& new_number_of_ants, size_t seed);

#endif
