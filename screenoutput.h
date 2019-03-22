// screenoutput.h
//
// Summarize and reports ants on a table.  Header file
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#ifndef REPORTH
#define REPORTH

#include <rarray>
// Function which computes the total number in a two dimensional 
// array, as well as the minimum and maximum, and reports these
// to the terminal.
//
// Paremeters:
//   number_of_ants   a two-dimensional rarray 
//   t                a counter that will be output to screen as well
//
// Returns:
//   the sum of all number_of_ents
//
int report_summary(const rarray<int,2>& number_of_ants, int t);

#endif
