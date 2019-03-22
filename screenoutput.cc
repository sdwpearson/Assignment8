// screenoutput.cc
//
// Summarize and reports ants on a table. 
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "screenoutput.h"
#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>

int screen_report_summary(const rarray<int,2>& number_of_ants, int t)
{
    // count ants and determine minimum and maximum number on a square
    int nmin = INT_MAX; // will hold the minimum number of ants on any square
    int nmax = 0;       // will hold the maximum number of ants on any square
    int total_ants = 0;
    for (int i = 0; i < number_of_ants.extent(0); i++) {
        for (int j = 0; j < number_of_ants.extent(1); j++) {
            total_ants += number_of_ants[i][j];
            if (nmin > number_of_ants[i][j]) {
                nmin = number_of_ants[i][j];
            }
            if (nmax < number_of_ants[i][j]) {
                nmax = number_of_ants[i][j];
            }
        }
    }
    std::cout << t << " " << total_ants << " " << nmin << " " << nmax << std::endl;
    return total_ants;
}
