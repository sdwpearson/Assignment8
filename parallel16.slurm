#!/bin/bash
# SLURM submission script for multiple serial jobs on Niagara
#
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=16
#SBATCH --time=4:00:00
#SBATCH --job-name ants-serial16
 
# Load modules
module load gcc hdf5 netcdf boost gnu-parallel
 
# DIRECTORY TO RUN - $SLURM_SUBMIT_DIR is the directory from which the job was submitted
cd $SLURM_SUBMIT_DIR
 
# Turn off implicit threading in Python, R
export OMP_NUM_THREADS=1
 
# EXECUTION COMMAND 
parallel --joblog runs16.log -j $SLURM_TASKS_PER_NODE \ --no-run-if-empty < subjobs



