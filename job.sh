#!/bin/bash
#SBATCH	--comment "CHPS0731"
#SBATCH	-J "RayTracing"

#SBATCH --error=job.%J.err
#SBATCH	--output=job.%J.out

#SBATCH	-p short
#SBATCH	--time=05:00:00

#SBATCH	--mem 1024
#SBATCH -c 28

#SBATCH --mail-user=<florent.denef@etudiant.univ-reims.fr>
#SBATCH	--mail-type=ALL,TIME_LIMIT_50,TIME_LIMIT_80

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

time ./prog Bunny.obj
