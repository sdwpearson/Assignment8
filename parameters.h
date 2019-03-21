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
// time_steps, total_ants, seed, and, datafile.
void read_parameters(const std::string &inifilename, 
                     int&         length,    //length of the table
                     int&         time_steps,//number of time steps to take
                     int&         total_ants,//initial number of ants
                     size_t&      seed,      //seed for random number generation
                     std::string& filename,  //name of the output file
                     int argc, char* argv[]);//command line args

#endif
