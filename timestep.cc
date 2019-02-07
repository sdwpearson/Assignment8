// timestep.cc
//
// Summarize and reports ants on a table.  
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "timestep.h"
#include "randompartition.h"

void perform_one_timestep(int* number_of_ants, int* new_number_of_ants, int length, size_t seed)
{
    const int nmoves = 9; // There are (3 in the i direction)x(3 in the j direction)=9 possible moves
    int* imoves = new int[nmoves] ; // Effect of each move on the i direction
    int* jmoves = new int[nmoves];  // Effect of each move on the j direction
    imoves[0] = -1; jmoves[0] = -1;
    imoves[1] = -1; jmoves[1] =  0;
    imoves[2] = -1; jmoves[2] =  1;
    imoves[3] =  0; jmoves[3] = -1;
    imoves[4] =  0; jmoves[4] =  0;
    imoves[5] =  0; jmoves[5] =  1;
    imoves[6] =  1; jmoves[6] = -1;
    imoves[7] =  1; jmoves[7] =  0;
    imoves[8] =  1; jmoves[8] =  1;
    int* partition = new int[nmoves];   // used to determine how many ants move in which direction in a time step

    // ants move to a new an auxiliary new 'table', empty this one first
    for (int i = 0; i < length;i++) {
        for (int j = 0; j < length;j++) {
            int n = i*length + j; // linear index
            new_number_of_ants[n] = 0;
        }
    }
    
    // now move ants into auxiliary table
    for (int i = 0; i < length;i++) {
        for (int j = 0; j < length;j++) {
            int n = i*length + j; // linear index
            if (number_of_ants[n] > 0 ) {
                // pick how many ants go in each of the 9 moves
                rand_partition(number_of_ants[n], nmoves, partition, seed);
                // push ants in their respective moves 
                for (int m = 0; m < nmoves; m++) {
                    int i2 = i + imoves[m];
                    int j2 = j + jmoves[m];
                    // put only on new table if not falling off table
                    if (i2>=0 and i2<length and j2>=0 and j2<length) {
                        int n = i2*length + j2; // linear index
                        new_number_of_ants[n] += partition[m];
                    }
                }
            }
        }
    }
    
    // update number_of_ants
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            int n = i*length + j; // linear index
            number_of_ants[n] = new_number_of_ants[n];
        }
    }

    delete[] partition;
    delete[] imoves;
    delete[] jmoves;
}

