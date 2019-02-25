/*
 * Title: HighpassFilter.h
 * 
 * Date: 25/02/2019
 * 
 * Author: Philip Salmony
 * Email: philip.salmony@gmail.com
 * 
 * Description: Collection of simple high-pass filters, first and second order.
 *              Approximately flat in pass-band, -3dB point defined by cut-off frequency.
 *              Attenuation slope is n * (-20dB/dec), where n is the filter order.
 *              
 */

#ifndef HIGHPASS_FILTER_H
#define HIGHPASS_FILTER_H

#include "Filter.h"

class HighpassFilter : public Filter {

  public:

    HighpassFilter(int n, float fc, float fs);
  
};

#endif
