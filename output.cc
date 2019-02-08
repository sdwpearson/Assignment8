// output.cc
//
// Will writes the 2d array of ants to a netcdf file. This is a stub
// (placeholder) of the implementation.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "output.h"

OutputHandle output_open(const std::string& filename, const int* shape)
{ 
   return OutputHandle(0); 
}

void output_write(OutputHandle& handle, const rarray<int,2>& number, int time)
{
}

void output_close(OutputHandle& handle)
{
}
