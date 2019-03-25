#!/bin/bash
# SLURM submission script for multiple serial jobs on Niagara
#
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=16
#SBATCH --time=12:00:00
#SBATCH --job-name ants-serial16
 
# Load modules
module load gcc hdf5 netcdf boost gnu-parallel
 
# DIRECTORY TO RUN - $SLURM_SUBMIT_DIR is the directory from which the job was submitted
cd $SLURM_SUBMIT_DIR
 
# Turn off implicit threading in Python, R
export OMP_NUM_THREADS=1
 
# EXECUTION COMMAND 
parallel --joblog runs016.log -j 16 --no-run-if-empty < subjobs16
parallel --joblog runs015.log -j 15 --no-run-if-empty < subjobs15
parallel --joblog runs014.log -j 14 --no-run-if-empty < subjobs14
parallel --joblog runs013.log -j 13 --no-run-if-empty < subjobs13
parallel --joblog runs012.log -j 12 --no-run-if-empty < subjobs12
parallel --joblog runs011.log -j 11 --no-run-if-empty < subjobs11
parallel --joblog runs010.log -j 10 --no-run-if-empty < subjobs10
parallel --joblog runs008.log -j 8 --no-run-if-empty < subjobs8
parallel --joblog runs009.log -j 9 --no-run-if-empty < subjobs9
parallel --joblog runs007.log -j 7 --no-run-if-empty < subjobs7
parallel --joblog runs006.log -j 6 --no-run-if-empty < subjobs6
parallel --joblog runs005.log -j 5 --no-run-if-empty < subjobs5
parallel --joblog runs004.log -j 4 --no-run-if-empty < subjobs4
parallel --joblog runs003.log -j 3 --no-run-if-empty < subjobs3
parallel --joblog runs002.log -j 2 --no-run-if-empty < subjobs2
parallel --joblog runs001.log -j 1 --no-run-if-empty < subjobs1



