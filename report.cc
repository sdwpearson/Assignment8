// report.cc
//
// Summarize and reports ants on a table. 
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "report.h"
#include <iostream>
#include <climits>

int report_summary(const int* number_of_ants, int length, int t)
{
    // count ants and determine minimum and maximum number on a square
    int nmin = INT_MAX; // will hold the minimum number of ants on any square
    int nmax = 0;       // will hold the maximum number of ants on any square
    int total_ants = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            int n = i*length + j; // linear index
            total_ants += number_of_ants[n];
            if (nmin > number_of_ants[n]) {
                nmin = number_of_ants[n];
            }
            if (nmax < number_of_ants[n]) {
                nmax = number_of_ants[n];
            }
        }
    }
    std::cout << t << " " << total_ants << " " << nmin << " " << nmax << std::endl;
    return total_ants;
}
