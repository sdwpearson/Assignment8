// initializationtest.cc
//
// testing uniform initialization of 2d arrays by the
// initialize_uniform function.
//
// Ramses van Zon, SciNet, Feb 2019

#include "initialization.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE initializationunittest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(initializationtest) {

   // parameters of 5 cases
   const int numcases = 5;
   const int params[numcases][3] = {
      { 1, 1, 11 },   // ilength, jlength, total
      { 2, 1, 11 },
      { 4, 1, 16 },
      { 4, 2, 27 },
      { 4, 7, 1133 }
   };
   
   for (int k = 0; k < numcases; k++) {
      // setup
      const int ilength = params[k][0];
      const int jlength = params[k][1];
      const int total = params[k][2];
      rarray<int,2> number(ilength, jlength);
      int minval = total/(ilength*jlength);
      int maxval = minval;
      if (minval*ilength*jlength < total) {
         maxval++;
      }
      // call function
      initialize_uniform(number, total);
      // check result
      for (int i=0; i<ilength; i++) {
         for (int j=0; j<jlength; j++) {
            BOOST_CHECK(minval <= number[i][j] and number[i][j] <= maxval);
         }
      }
   }

}
