/*
 * Title: LowpassFilter.h
 * 
 * Date: 25/02/2019
 * 
 * Author: Philip Salmony
 * Email: philip.salmony@gmail.com
 * 
 * Description: Collection of simple low-pass filters, first and second order.
 *              Approximately flat in pass-band, -3dB point defined by cut-off frequency.
 *              Attenuation slope is n * (-20dB/dec), where n is the filter order.
 *              
 */

#ifndef LOWPASS_FILTER_H
#define LOWPASS_FILTER_H

#include "Filter.h"

class LowpassFilter : public Filter {

  public:

    LowpassFilter(int n, float fc, float fs);
  
};

#endif
