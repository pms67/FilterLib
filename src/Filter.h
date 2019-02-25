/*
 * Title: Filter.h
 * 
 * Date: 25/02/2019
 * 
 * Author: Philip Salmony
 * Email: philip.salmony@gmail.com
 * 
 * Description: Class prototype for implementation of digital filters.
 *              Assumes implementation using Tustin transform, therefore require
 *              prewarp function.
 *              Note that the Tustin transform is only an approximation, which guarantees
 *              an exact match ONLY AT the desired cut-off frequency. This is especially true
 *              for cut-off frequencies close to the Nyquist frequency (fs/2).
 *              To get a better frequency-domain match between analogue prototype and digital
 *              approximation, sample at a higher frequency.
 */

#ifndef FILTER_H
#define FILTER_H

#include <math.h>

#define FILTER_MAX_ORDER 4

class Filter {

  protected:   

    float wc, T;
    
    int order;
    float num[FILTER_MAX_ORDER + 1];
    float den[FILTER_MAX_ORDER + 1];

    float u[FILTER_MAX_ORDER + 1];
    float y[FILTER_MAX_ORDER + 1];
    
    void prewarp(float fc, float fs);

  public:

    float getwc();
    float getT();
    
    void reset();
    float update(float val);
  
};

#endif
