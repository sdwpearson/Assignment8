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
#include "output.h"
#include "parameters.h"

void printhelp(std::ostream& out)
{
   out << "antsontable - Simulation of ants walking on a table.\n"
       << "\n"
       << "The table is subdivided into squares. A number of ants is initially\n"
       << "put on the table, divided as evenly as possible over the squares.  \n"
       << "Ants can move to a neighbouring square or stay put at every time step.\n"
       << "How many of a square's ants move in each of the 9 different directions\n"
       << "is random.  Ants can fall of the edges of the table. The program \n"
       << "prints the number of ants left on the table after every time step,\n"
       << "as well as the minimum number of ants on a square and the maximum.\n"
       << "The full ants data is written to a netcdf file.\n"
       << "\n"
       << "Usage:"
       << "  antsontable [inifile] [--length=<L>] [--time_steps=<T>] \n"
       << "              [--total_ants=<N>] [--seed=<S>] [--filename=<F>]\n"
       << "\n"
       << "where\n"
       << "  <inifile> is a file containing parameters\n"
       << "  --length=<L>      length of the table (overrides inifile setting)\n"
       << "  --time_steps=<T>  number of time steps to take (overrides inifile setting)\n"
       << "  --total_ants=<N>  initial number of ants (overrides inifile setting)\n"
       << "  --seed=<S>        seed for random number generation (overrides inifile setting)\n"
       << "  --filename=<T>    name of the output netcdf file\n"
       << "\n";
}


// Main driver function of antsontable.cc
int main(int argc, char* argv[])
{
    // parameters
    int         length     = 70;        // length of the table
    int         time_steps = 10000;     // number of time steps to take
    int         total_ants = 40000;     // initial number of ants
    size_t      seed       = 11;        // seed for random number generation
    std::string filename   = "ants.nc"; // output filename
    std::string paramfile  = "params.ini"; // parameter file

    // deal with reading in parameters from a file or from the command line
    if ( (argc > 1) and (strcmp(argv[1],"--help")==0)) {
       printhelp(std::cout);
       return 0;
    }
    if ( (argc > 1) and (argv[1][0] != '-') ) {
       paramfile = std::string(argv[1]);
       argv++;
       argc--;
    }
    try {
       read_parameters(paramfile, length, time_steps, total_ants, seed, filename, argc, argv);
    } 
    catch (std::exception& e) {
       std::cerr << "Error: " << e.what() << std::endl;
       printhelp(std::cerr);
       return 1;
    }
    std::cerr << "# length = "     << length << "\n"
              << "# time_steps = " << time_steps << "\n"
              << "# total_ants = " << total_ants << "\n"
              << "# seed = "       << seed << "\n"
              << "# filename = "   << filename << "\n";

    // work arrays
    rarray<int,2> number_of_ants(length,length);     // distribution of ants on the table over squares.
    rarray<int,2> new_number_of_ants(length,length); // auxiliary array used in time step to hold the new distribution of ants
    // prepare output file
    OutputHandle handle = output_open(filename, number_of_ants.shape());
    
    // place the ants evenly on the table
    initialize_uniform(number_of_ants, total_ants);

    // count ants, report and output to file
    total_ants = report_summary(number_of_ants, 0);
    output_write(handle, number_of_ants, 0);

    // run time steps
    for (int t = 0; t < time_steps; t++) {

        // move ants on the table (some fall off)
        perform_one_timestep(number_of_ants, new_number_of_ants, seed);
                
        // count ants and report
        total_ants = report_summary(number_of_ants, t+1);

        // output every 1000 timesteps
        if (t%1000 == 0) {
           output_write(handle, number_of_ants, t+1);
        }
    }

    output_close(handle);

    return 0;
}             

