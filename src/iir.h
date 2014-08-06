#ifndef _IIR_H
#define _IIR_H

#include <vector>
#include <complex>
#include <stdexcept>

#define _USE_MATH_DEFINES
#include <math.h>

#include "factor.h"


// calculate transfer function H(z) of IIR filter
// v: output (H(z)), f: freq, a,b: factors
void
iir (std::vector<std::complex<double> >& v, const Freq& f, const std::vector<double>& a, const std::vector<double>& b);

// f: freq
std::complex<double> freq_to_z (const double f);

std::complex<double>
iir_calc(const std::complex<double> z, const std::vector<double>& a, const std::vector<double>& b);

// calculate phase and group delay
// a: output (phase),  d: output (group delay)
void arg_group_delay (std::vector<double>& a, std::vector<double>& d, const std::vector<std::complex<double> >& v, const double df);

#endif
