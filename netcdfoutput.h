// netcdfoutput.h
//
// Writes the 2d array of ants to a netcdf file. 
//
// Ramses van Zon, SciNet, University of Toronto
// January-March 2019

#ifndef NETCDFOUTPUTH
#define NETCDFOUTPUTH

#pragma GCC diagnostic ignored "-Wunused-variable"

#include <string>
#include <rarray>
#include <memory>
#include <netcdf>

// Because NetCFD file objects cannot be copied, we define an OutputHandle 
// object that can, and can be returned from a function 
struct NetCDFOutputHandle // handle on an open file 
{
   std::shared_ptr<netCDF::NcFile> file;
   netCDF::NcVar time;
   netCDF::NcVar ants;
   size_t record;
};  


// The function netcdf_output_open opens the netcdf file 'filename' and prepares an integer-valued 
// three-dimensional variable in it.  The variable has a first unlimited dimension, while the remaining 
// two dimensions are determined by the 'shape' argument.
//
// Parameters:
//  filename    name of the netcdf file to create
//  shape       a pointer to the first element of a two-dimensional array that holds the last two dimensions.
//              (i.e., the matrices to be stored are of size shape[0] x shape[1])
//
// Returns: 
//  a variable of type NetCDFOutputHandle
// 
NetCDFOutputHandle netcdf_output_open(const std::string& filename, const int* shape);


// The function output_write writes one slice of the variable stored in the netcdf file. The dimension of the
// number matrix must be the same as the shape that was given to the output_open function.
//
// Parameters:
//  handle    a variable of type NetCDFOutputHandle (by reference) 
//  number    a matrix to write to file (by reference) 
//
void netcdf_output_write(NetCDFOutputHandle& handle, const rarray<int,2>& number, int time);

// The function netcdf_output_close closes the netcdf file associated with the NetCDFOutputHandle handle.
//
// Parameters:
//  handle    a variable of type NetCDFOutputHandle (by reference) 
// 
void netcdf_output_close(NetCDFOutputHandle& handle);

#endif
