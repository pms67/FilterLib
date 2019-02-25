/*
 * Title: ButterworthLPF.h
 * 
 * Date: 25/02/2019
 * 
 * Author: Philip Salmony
 * Email: philip.salmony@gmail.com
 * 
 * Description: Collection of Butterworth low-pass filters, first order through to fourth order.
 *              Starting from analogue prototype transfer functions, using Tustin (bilinear) transform to
 *              to arrive at digital approximation.
 *              Buttworth filters are 'maximally flat' before cut-off frequency, i.e. in passband.
 *              Gain of any order Butterworth low-pass filter at cut-off frequency is -3dB (1/sqrt(2)).
 *              However, attenuation slope is n * (-20dB/dec), where n is the filter order.
 *              
 */

#ifndef BUTTERWORTHLPF_H
#define BUTTERWORTHLPF_H

#include "Filter.h"

class ButterworthLPF : public Filter {

  public:

    ButterworthLPF(int n, float fc, float fs);
  
};

#endif
