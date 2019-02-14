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
   handle.time.putVar({handle.record}, {1}, &time);
   handle.ants.putVar({handle.record,0,0}, {1,size_t(number.extent(0)),size_t(number.extent(1))}, number.data());
   handle.record++;
}

void output_close(OutputHandle& handle)
{
   handle.file = nullptr; // file closes automatically
   // for good measure:
   handle.ants = netCDF::NcVar();
   handle.time = netCDF::NcVar();
   handle.record = 0;
}
