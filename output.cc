// output.cc
//
// Will writes the 2d array of ants to a netcdf file. This is a stub
// (placeholder) of the implementation.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "output.h"
#include <vector>

using namespace netCDF;

OutputHandle output_open(const std::string& filename, const int* shape)
{
   OutputHandle handle;
   handle.file = std::make_shared<NcFile>(filename, NcFile::replace);
   NcDim tdim = handle.file->addDim("t");
   NcDim xdim = handle.file->addDim("x",shape[0]);
   NcDim ydim = handle.file->addDim("y",shape[1]);
   handle.ants = handle.file->addVar("ants", ncInt, {tdim,xdim,ydim});
   handle.record = 0;
   return handle;
}

void output_write(OutputHandle& handle, const rarray<int,2>& number, int time)
{
   handle.ants.putVar({handle.record,0,0}, {1,size_t(number.extent(0)),size_t(number.extent(1))}, number.data());
   handle.record++;
}

void output_close(OutputHandle& handle)
{
   handle.file = nullptr; // file closes automatically
   handle.ants = netCDF::NcVar();
   handle.record = 0;
}
