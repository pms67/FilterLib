#include "ButterworthLPF.h"

ButterworthLPF::ButterworthLPF(int n, float fc, float fs) {

  // Set filter order and check bounds
  order = n;
  
  if (order > 4) // Only up to fourth order at the moment...
    order = 4;
  else if (order < 1)
    order = 1;

  // Pre-warp cut-off frequency (Tustin)
  prewarp(fc, fs);

  // Reset filter inputs and outputs
  reset();

  // Set filter numerator and denominator coefficients
  float wcT   = wc * T;
  float wcTsq = wcT * wcT;
  float wcTcu = wcT * wcTsq;
  float wcTfo = wcTsq * wcTsq;

  float alpha = 2.6132;
  float beta  = 3.41430612;
  
  switch (order) {

    case 1:

      num[0] = wcT;
      num[1] = wcT;

      den[0] =  2 + wcT;
      den[1] = -2 + wcT;
      break;

    case 2:     

      num[0] =     wcTsq;
      num[1] = 2 * wcTsq;
      num[2] =     wcTsq;

      den[0] =  4 + 2.8284 * wcT + wcTsq;
      den[1] = -8 +            2 * wcTsq;
      den[2] =  4 - 2.8284 * wcT + wcTsq;
      break;

    case 3:

      num[0] =     wcTcu;
      num[1] = 3 * wcTcu;
      num[2] = 3 * wcTcu;
      num[3] =     wcTcu;

      den[0] =    8 + 8 * wcT + 4 * wcTsq +     wcTcu;
      den[1] = -24  - 8 * wcT + 4 * wcTsq + 3 * wcTcu;
      den[2] =  24 -  8 * wcT - 4 * wcTsq + 3 * wcTcu;
      den[3] =   -8 + 8 * wcT - 4 * wcTsq +     wcTcu;
      break;

    case 4:

      num[0] =     wcTfo;
      num[1] = 4 * wcTfo;
      num[2] = 6 * wcTfo;
      num[3] = 4 * wcTfo;
      num[4] =     wcTfo;

      den[0] =  16 +  8 * alpha * wcT + 4 * beta * wcTsq + 2 * alpha * wcTcu +     wcTfo;
      den[1] = -64 - 16 * alpha * wcT                    + 4 * alpha * wcTcu + 4 * wcTfo;
      den[2] =  96                    - 8 * beta * wcTsq                     + 6 * wcTfo;
      den[3] = -64 + 16 * alpha * wcT                    - 4 * alpha * wcTcu + 4 * wcTfo;
      den[4] =  16 -  8 * alpha * wcT + 4 * beta * wcTsq - 2 * alpha * wcTcu +     wcTfo;      
      break;

  }
  
}

