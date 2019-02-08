// timestep.cc
//
// Summarize and reports ants on a table.  
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include "timestep.h"
#include "randompartition.h"

void perform_one_timestep(rarray<int,2>& number_of_ants, rarray<int,2>& new_number_of_ants, size_t seed)
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
    rarray<int,1> partition(nmoves);   // used to determine how many ants move in which direction in a time step

    // ants move to a new an auxiliary new 'table', empty this one first
    new_number_of_ants.fill(0);
    
    // now move ants into auxiliary table
    for (int i = 0; i < number_of_ants.extent(0); i++) {
        for (int j = 0; j < number_of_ants.extent(1); j++) {
            if (number_of_ants[i][j] > 0 ) {
                // pick how many ants go in each of the 9 moves
                rand_partition(number_of_ants[i][j], nmoves, partition, seed);
                // push ants in their respective moves 
                for (int m = 0; m < nmoves; m++) {
                    int i2 = i + imoves[m];
                    int j2 = j + jmoves[m];
                    // put only on new table if not falling off table
                    if (i2>=0 and i2<number_of_ants.extent(0) and j2>=0 and j2<number_of_ants.extent(1)) {
                        new_number_of_ants[i2][j2] += partition[m];
                    }
                }
            }
        }
    }
    
    // update number_of_ants
    for (int i = 0; i < number_of_ants.extent(0); i++) {
        for (int j = 0; j < new_number_of_ants.extent(1); j++) {
            number_of_ants[i][j] = new_number_of_ants[i][j];
        }
    }

    delete[] imoves;
    delete[] jmoves;
}

