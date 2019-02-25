#include "Filter.h"

void Filter::prewarp(float fc, float fs) {

  // Check bounds on fs, prevent divide by zero or negative fs
  if (fs < 0)
    fs = 1.0;

  // Check that fc <= fs / 2 (Nyquist)
  if (fc > fs / 2.0)
    fc = fs / 2.0;
  else if (fc < 0.0)
    fc = 0.0;

  T = 1 / fs;
  wc = (2 / T) * tan(M_PI * fc / fs);
  
}

float Filter::getwc() {

  return wc;
  
}

float Filter::getT() {

  return T;
  
}

void Filter::reset() {

  for (int i = 0; i <= order; i++) {
    u[i] = 0.0;
    y[i] = 0.0;
  }
  
}

float Filter::update(float val) {

  int i;

  // Shift samples
  for (i = order; i > 0; i--) {
    u[i] = u[i - 1];
    y[i] = y[i - 1];
  }

  // Set new input
  u[0] = val;

  // Calculate new output
  y[0] = 0.0;

  for (i = 0; i <= order; i++) {
    y[0] += num[i] * u[i];

    if (i > 0)
      y[0] -= den[i] * y[i];
    
  }

  y[0] /= den[0];

  return y[0];

}
