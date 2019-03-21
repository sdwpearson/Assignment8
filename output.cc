// output.cc
//
// Will writes the 2d array of ants to a netcdf file. This is a stub
// (placeholder) of the implementation.
//
// Ramses van Zon, SciNet, University of Toronto
// January-February 2019

#include "output.h"

OutputHandle output_open(const std::string& filename, const int* shape)
{
   // Opens the netcdf file 'filename' and prepares an integer-valued
   // three-dimensional variable in it.  The variable has a first
   // unlimited dimension, while the remaining two dimensions are
   // determined by the 'shape' argument.
   //
   // Parameters:
   //  filename    name of the netcdf file to create
   //  shape       a pointer to the first element of a two-dimensional 
   //              array that holds the last two dimensions.  (i.e., 
   //              the matrices to be stored are of size 
   //              shape[0] x shape[1])
   //
   // Returns: 
   //  a variable of type OutputHandle
   OutputHandle handle;
   handle.file = std::make_shared<netCDF::NcFile>(filename, 
                                                  netCDF::NcFile::replace);
   handle.file->putAtt("description", "antsontable data");
   netCDF::NcDim tdim = handle.file->addDim("t");
   netCDF::NcDim xdim = handle.file->addDim("x", shape[0]);
   netCDF::NcDim ydim = handle.file->addDim("y", shape[1]);
   handle.time = handle.file->addVar("time", netCDF::ncInt, {tdim});
   handle.ants = handle.file->addVar("ants", netCDF::ncInt, {tdim,xdim,ydim});
   handle.record = 0;
   return handle;
}

void output_write(OutputHandle& handle, const rarray<int,2>& number, int time)
{
   // Writes one slice of the variable stored in the netcdf file. The
   // dimension of the number matrix must be the same as the shape
   // that was given to the output_open function.
   // Parameters:
   //  handle    a variable of type OutputHandle (by reference) 
   //  number    a matrix to write to file (by reference) 
   handle.time.putVar({handle.record}, {1}, &time);
   handle.ants.putVar({handle.record,0,0}, {1,size_t(number.extent(0)),size_t(number.extent(1))}, number.data());
   handle.record++;
}

void output_close(OutputHandle& handle)
{
   // Closes the netcdf file associated with the OutputHandle handle.
   // Parameter:  handle, a variable of type OutputHandle (by reference) 
   handle.file = nullptr; // file closes automatically
   // for good measure:
   handle.ants = netCDF::NcVar();
   handle.time = netCDF::NcVar();
   handle.record = 0;
}
