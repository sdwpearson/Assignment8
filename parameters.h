// 
// parameters.h
//
// Module for reading parameters for antsontable
//

#ifndef PARAMETERSH
#define PARAMETERSH

#include <string>
#include <iosfwd>

// The function 'read_parameters' reads in the file inifilename and
// stores the parameters in that file in the variables length,
// time_steps, total_ants, seed, filename, and output_steps.
//
// Parameters
//  length:              reference to an integer to be filled with the 'length' parameter
//  time_steps:          reference to an integer to be filled with the 'time_steps' parameter
//  total_ants:          reference to an integer to be filled with the 'total_ants' parameter
//  seed:                reference to a size_t integer to be filled with the 'seed' parameter
//  filename:            reference to a string to be filed with the filename parameter
//  netcdf_output_steps: reference to an integer to be filed with number of steps between netcdf output
//  screen_output_steps: reference to an integer to be filed with number of steps between screen output
//  argc,argv:           command line arguments that can override the parameters found in the parameter file
//                         arguments should be of the form "--length=<value>"
//  help:                function that can display the usage/help message
//
void parameters(int&         length,       //length of the table
                int&         time_steps,   //number of time steps to take
                int&         total_ants,   //initial number of ants
                size_t&      seed,         //seed for random number generation
                std::string& filename,     //name of the output file
                int&         netcdf_output_steps,// number of steps between netcdf output
                int&         screen_output_steps,// number of steps between screen output
                int          argc,            // number of command line args
                char*        argv[],          // command line args
                void (*help)(std::ostream&)); // help display function

#endif
