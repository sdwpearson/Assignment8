// 
// parameters.h
//
// Module for reading parameters for antsontable
//

#ifndef PARAMETERSH
#define PARAMETERSH

#include <string>

// The function 'read_parameters' reads in the file inifilename and
// stores the parameters in that file in the variables length,
// time_steps, total_ants, seed, filename, and output_steps.
//
// Parameters
//  inifilename:  filename of the parameter file to read in
//  length:       reference to an integer to be filled with the 'length' parameter
//  time_steps:   reference to an integer to be filled with the 'time_steps' parameter
//  total_ants:   reference to an integer to be filled with the 'total_ants' parameter
//  seed:         reference to a size_t integer to be filled with the 'seed' parameter
//  filename:     reference to a string to be filed with the filename parameter
//  output_steps: reference to an integer to be filed with number of steps between output
//  argc,argv:    command line arguments that can override the parameters found in the parameter file
//                 arguments should be of the form "--length=<value>"
//
void read_parameters(const std::string &inifilename, 
                     int&         length,       //length of the table
                     int&         time_steps,   //number of time steps to take
                     int&         total_ants,   //initial number of ants
                     size_t&      seed,         //seed for random number generation
                     std::string& filename,     //name of the output file
                     int&         output_steps, // number of steps between output
                     int argc, char* argv[]);   //command line args

#endif
