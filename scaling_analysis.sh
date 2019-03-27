#!/bin/bash

# Run the slurm script 16 times while varying the cores from 1 to 16
sbatch parallel16.slurm
echo "submitted 16 core job"
sbatch parallel15.slurm
echo "submitted 15 core job"
sbatch parallel14.slurm
echo "submitted 14 core job"
sbatch parallel13.slurm
echo "submitted 13 core job"
sbatch parallel12.slurm
echo "submitted 12 core job"
sbatch parallel11.slurm
echo "submitted 11 core job"
sbatch parallel10.slurm
echo "submitted 10 core job"
sbatch parallel9.slurm
echo "submitted 9 core job"
sbatch parallel8.slurm
echo "submitted 8 core job"
sbatch parallel7.slurm
echo "submitted 7 core job"
sbatch parallel6.slurm
echo "submitted 6 core job"
sbatch parallel5.slurm
echo "submitted 5 core job"
sbatch parallel4.slurm
echo "submitted 4 core job"
sbatch parallel3.slurm
echo "submitted 3 core job"
sbatch parallel2.slurm
echo "submitted 2 core job"
sbatch parallel1.slurm
echo "submitted 1 core job"

