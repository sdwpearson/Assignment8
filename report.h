// report.h
//
// Summarize and reports ants on a table.  Header file
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#ifndef REPORTH
#define REPORTH

// FUnction which computes the total number in a two dimensional 
// array, as well as the minimum and maximum, and reports these
// to the terminal.
//
// Paremeters:
//   number_of_ants   pointer to the first elements of a two-dimensional array
//   length           size of both dimensions of the array
//   t                a counter that will be output to screen as well
//
// Returns:
//   the sum of all number_of_ents
//
int report_summary(const int* number_of_ants, int length, int t);

#endif
