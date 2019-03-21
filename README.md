# Code for the ants-on-table application for phy1610

module load gcc hdf5 netcdf boost
make
make test # optional

This creates the antsontable executable, which simulates ants walking
on a table.

The table is subdivided into squares. A number of ants is initially
put on the table, divided as evenly as possible over the squares.
Ants can move to a neighbouring square or stay put at every time step.
How many of a square's ants move in each of the 9 different directions
is random.  Ants can fall of the edges of the table. The program
prints the number of ants left on the table after every time step, as
well as the minimum number of ants on a square and the maximum.  The
full ants data is written to a netcdf file.

Usage:
  antsontable [<inifile>] [--length=<L>] [--time_steps=<T>] 
            [--total_ants=<N>] [--seed=<S>] [--filename=<F>]

where
  <inifile> is a file containing parameters
  --length=<L>      length of the table (overrides inifile setting)
  --time_steps=<T>  number of time steps to take (overrides inifile setting)
  --total_ants=<N>  initial number of ants (overrides inifile setting)
  --seed=<S>        seed for random number generation (overrides inifile setting)
  --filename=<T>    name of the output netcdf file

