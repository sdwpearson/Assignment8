// antsontable.cc
//
// Simulation of ants walking on a table. The table is subdivided into
// squares. A number of ants is initially put on the table, divided as
// evenly as possible over the squares.  Ants can move to a
// neighbouring square or stay put at every time step.  How many of a
// square's ants move in each of the 9 different directions is random
// (using c++11's random library).  Ants can fall of the edges of the
// table. The program prints the number of ants left on the table
// after every time step, as well as the minimum number of ants on a
// square and the maximum.
//
// This is the part of the example solution for assignment 2 for the
// scientific computing course PHY1610H given in the Winter of 2019.
//
// Compile with 'make'.
// On the clusters, it will be necessary to load the "gcc" module first.
//
// Run with
//
//     ./antsontable > output.dat
//
// This saves the output to the file output.dat instead of writing it to
// screen.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include <iostream>
#include <random>
#include <algorithm>
#include <rarray>
#include "initialization.h"
#include "report.h"
#include "timestep.h"

// Main driver function of antsontable.cc
int main()
{
    // parameters
    int    length     = 70;     // length of the table
    int    time_steps = 10000;  // number of time steps to take
    int    total_ants = 40000;  // initial number of ants
    size_t seed       = 11;     // seed for random number generation

    // work arrays
    rarray<int,2> number_of_ants(length,length);     // distribution of ants on the table over squares.
    rarray<int,2> new_number_of_ants(length,length); // auxiliary array used in time step to hold the new distribution of ants
    
    // place the ants evenly on the table
    initialize_uniform(number_of_ants, total_ants);

    // count ants and report
    total_ants = report_summary(number_of_ants, 0);

    // run time steps
    for (int t = 0; t < time_steps; t++) {

        // move ants on the table (some fall off)
        perform_one_timestep(number_of_ants, new_number_of_ants, seed);
                
        // count ants and report
        total_ants = report_summary(number_of_ants, t+1);
    }

    return 0;
}             

