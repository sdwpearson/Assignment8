// 
// parameters.cc
//
// Module for reading parameters for antsontable
//

#include "parameters.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class Inifile
{
  public:
    Inifile()
    {}
   Inifile(const std::string filename, int argc, char* argv[]) {
       read(filename.c_str(), argc, argv);
    }
    void read(const std::string filename, int argc, char* argv[])  {
       if (filename.size() > 0)
          boost::property_tree::ini_parser::read_ini(filename, pt);
       if (argc > 1) {
          std::vector<std::string> args;
          for (int i = 1; i < argc; i++) 
             args.push_back(std::string(argv[i]));
          std::string cmdline = boost::algorithm::join(args, " ");
          boost::replace_all(cmdline, "--", "\n");
          std::stringstream cmdlinestream(cmdline);
          boost::property_tree::ptree ptarg;
          boost::property_tree::ini_parser::read_ini(cmdlinestream, ptarg);
          for (auto& keyvalue: ptarg)
             pt.put_child(keyvalue.first, keyvalue.second);
       }
    }
    template<typename T>
    T get(const std::string str) const {
        return pt.get<T>(str);
    }
    template<typename T>
    T get(const std::string str, T defval) const {
       T result;
       try {
          result = pt.get<T>(str);
       }
       catch (...) {
          result = defval;
       }
       return result;
    }
  private:
    boost::property_tree::ptree pt;
};

void read_parameters(const std::string &inifilename, 
                     int&         length,       //length of the table
                     int&         time_steps,   //number of time steps to take
                     int&         total_ants,   //initial number of ants
                     size_t&      seed,         //seed for random number generation
                     std::string& filename,     //name of the output file
                     int&         netcdf_output_steps,// number of steps between netcdf output
                     int&         screen_output_steps,// number of steps between screen output
                     int argc, char* argv[])    //command line args
{
  // This function reads in the file inifilename and stores the
  // parameters in that file in the variables length, time_steps,
  // total_ants, seed, filename, and output_steps.

  // Open inifile and parse (using Inifile class)
  Inifile parameter(inifilename, argc, argv);
      
  // Simulation parameters (defaults are given in case they are not in the file or on the command line)
  length       = parameter.get<int>("length",     70);
  time_steps   = parameter.get<int>("time_steps", 10000);
  total_ants   = parameter.get<int>("total_ants", 40000);
  seed         = parameter.get<size_t>("seed",    11);
  // Output parameters
  filename     = parameter.get<std::string>("filename", "ants.nc");
  netcdf_output_steps = parameter.get<int>("netcdf_output_steps", 1000);
  screen_output_steps = parameter.get<int>("screen_output_steps", 1);
}

void parameters(int&         length,       //length of the table
                int&         time_steps,   //number of time steps to take
                int&         total_ants,   //initial number of ants
                size_t&      seed,         //seed for random number generation
                std::string& filename,     //name of the output file
                int&         netcdf_output_steps,// number of steps between netcdf output
                int&         screen_output_steps,// number of steps between screen output
                int          argc, char* argv[],    //command line args
                void (*help)(std::ostream&)) // help display function
{
    std::string paramfile    = "";          // parameter file
    if ( (argc > 1) and (strcmp(argv[1],"--help")==0)) {
        help(std::cout);
        exit(0);
    }
    if ( (argc > 1) and (argv[1][0] != '-') ) {
        paramfile = std::string(argv[1]);
        argv++;
        argc--;
    }
    try {
        read_parameters(paramfile, length, time_steps, total_ants, seed, filename, netcdf_output_steps, screen_output_steps, argc, argv);
    } 
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        help(std::cerr);
        exit(1);
    }
}
