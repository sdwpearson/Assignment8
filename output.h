// output.h
//
// Writes the 2d array of ants to a netcdf file. This is a stub
// (placeholder) of the header file.
//
// Ramses van Zon, SciNet, University of Toronto
// January-February 2019

#ifndef OUTPUTH
#define OUTPUTH

#include <string>
#include <rarray>
#include <memory>
#include <netcdf>

struct OutputHandle // handle on an open file 
{
   std::shared_ptr<netCDF::NcFile> file;
   netCDF::NcVar time;
   netCDF::NcVar ants;
   size_t record;
};  

OutputHandle output_open(const std::string& filename, const int* shape);
void output_write(OutputHandle& handle, const rarray<int,2>& number, int time);
void output_close(OutputHandle& handle);

#endif
