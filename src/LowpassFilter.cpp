#include "LowpassFilter.h"

LowpassFilter::LowpassFilter(int n, float fc, float fs) {

  // Set filter order and check bounds
  order = n;
  
  if (order > 2) // Only up to second order at the moment...
    order = 2;
  else if (order < 1)
    order = 1;

  // Pre-warp cut-off frequency (Tustin)
  prewarp(fc, fs);

  // Reset filter inputs and outputs
  reset();

  // Set filter numerator and denominator coefficients
  float wcT   = wc * T;
  float wcTsq = wcT * wcT;
  
  switch (order) {

    case 1:

      num[0] = wc;
      num[1] = wc;

      den[0] =  2 + wcT;
      den[1] = -2 + wcT;
      break;

    case 2:     

      num[0] =     wcTsq;
      num[1] = 2 * wcTsq;
      num[2] =     wcTsq;

      den[0] =  4 + 4 * wcT +     wcTsq;
      den[1] = -8 +           2 * wcTsq;
      den[2] =  4 - 4 * wcT +     wcTsq;
      break;

  }
  
}

