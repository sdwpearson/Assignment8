// randompartition.h
// Ramses van Zon, SciNet, University of Toronto
// January 2019
#ifndef RANDOMPARTITIONH
#define RANDOMPARTITIONH

#include <rarray>
// Function to randomly divide a number 'total' into a set of
// 'numdivision' numbers that add up to 'total'.
//
// Parameters:
//   total     number that is to be subdivided (input)
//   nparts    number of partitions into which to divide 'total (input)
//   nperpart  1d rarray with resulting number in each partition (output)
//   seed      the seed for the random number generator (input)
//
void rand_partition(int total, int nparts, rarray<int,1>& nperpart, size_t seed);

#endif
