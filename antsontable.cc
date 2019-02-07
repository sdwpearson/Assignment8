// antsontable.cc
//
// Simulation of ants walking on a table. The table is subdivided into
// squares. A number of ants is initially put on the table, divided as
// evenly as possible over the squares.  Ants can move to a
// neighbouring square or stay put at every time step.  How many of a
// square's ants move in each of the 9 different directions is random
// (using c++11's random library).  Ants can fall of the edges of the
// table. The program prints the number of ants left on the table
// after every time step, as well as the minimum number of ants on a
// square and the maximum.
//
// This is the code for assignment 2 for the scientific computing course
// PHY1610H given in the Winter of 2019.
//
// Compile with:
//
//     g++ -std=c++11 -O3 -march=native -o antsontable antsontable.cc 
//  
// On the clusters, it will be necessary to load the "gcc" module first.
//
// Run with
//
//     ./antsontable > output.dat
//
// This saves the output to the file output.dat instead of writing it to
// screen.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include <iostream>
#include <random>
#include <algorithm>

const int nmoves = 9; // There are (3 in the i direction)x(3 in the j direction)=9 possible moves
const int imoves[nmoves] = {-1,-1,-1, 0, 0, 0, 1, 1, 1}; // Effect of each move on the i direction
const int jmoves[nmoves] = {-1, 0, 1,-1, 0, 1,-1, 0, 1}; // Effect of each move on the j direction

// Function to randomly divide a number 'total' into a set of
// 'numdivision' numbers that add up to 'total'.
//
// Parameters:
//   total     number that is to be subdivided (input)
//   nparts    number of partitions into which to divide 'total (input)
//   nperpart  resulting number in each partition (output)
//   seed      the seed for the random number generator (input)
//
void rand_partition(int total, int nparts, int* nperpart, size_t seed);

// Main driver function of antsontable.cc
int main()
{
    // parameters
    int    length     = 70;     // length of the table
    int    time_steps = 10000;  // number of time steps to take
    int    total_ants = 40000;  // initial number of ants
    size_t seed       = 11;     // seed for random number generation

    // work arrays
    int number_of_ants[length*length];     // distribution of ants on the table over squares.
    int new_number_of_ants[length*length]; // auxiliary array used in time step to hold the new distribution of ants
    int partition[nmoves];                 // used to determine how many ants move in which direction in a time step
    int nmin = total_ants;                 // will hold the minimum number of ants on any square
    int nmax = 0;                          // will hold the maximum number of ants on any square                        
    
    // place the ants evenly on the table
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            int n = i*length + j; // linear index
            number_of_ants[n] = ((long long)(n+1)*total_ants)/(length*length) - ((long long)(n)*total_ants)/(length*length);
        }
    }

    // count ants and determine minimum and maximum number on a square
    nmin = total_ants;
    nmax = 0;
    total_ants = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            int n = i*length + j; // linear index
            total_ants += number_of_ants[n];
            if (nmin > number_of_ants[n]) {
                nmin = number_of_ants[n];
            }
            if (nmax < number_of_ants[n]) {
                nmax = number_of_ants[n];
            }
        }
    }

    // report
    std::cout << 0 << " " << total_ants << " " << nmin << " " << nmax << std::endl;

    // run time steps
    for (int t = 0; t < time_steps; t++) {
        
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
        
        // count ants and determine minimum and maximum number on a square
        nmin = total_ants;
        nmax = 0;
        total_ants = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                int n = i*length + j; // linear index
                total_ants += number_of_ants[n];
                if (nmin > number_of_ants[n]) {
                    nmin = number_of_ants[n];
                }
                if (nmax < number_of_ants[n]) {
                    nmax = number_of_ants[n];
                }
            }
        }
        
        // report
        std::cout << t+1 << " " << total_ants << " " << nmin << " " << nmax << std::endl;
    }
    return 0;
}             

// Implementation of the function to randomly divide a number 'total'
// into a set of 'numdivision' numbers that add up to 'total'. Uses
// c++11 random library to generate the randomness.
void rand_partition(int total, int nparts, int* nperpart, size_t seed)
{
    // never mind the implementation, we'll see how this works in a future lecture.
    static std::mt19937 engine(seed);
    std::uniform_int_distribution<int> uniformint(0, total);

    nperpart[0] = 0;
    for (int k = 1; k < nparts; k++)
        nperpart[k] = uniformint(engine);

    std::sort(nperpart, nperpart + nparts);

    for (int k = 0; k < nparts-1; k++)
        nperpart[k] = nperpart[k+1] - nperpart[k];
    
    nperpart[nparts-1] = total - nperpart[nparts-1]; 
}

