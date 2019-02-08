// output.h
//
// Writes the 2d array of ants to a netcdf file. This is a stub
// (placeholder) of the header file.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#ifndef OUTPUTH
#define OUTPUTH

#include <string>
#include <rarray>

typedef int OutputHandle; // this stub type will change to a valid
                          // handle on an open file in the real
                          // implementation.


OutputHandle output_open(const std::string& filename, const int* shape);

void output_write(OutputHandle& handle, const rarray<int,2>& number, int time);

void output_close(OutputHandle& handle);

#endif
