#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <complex>
#include <vector>
#include <string>
#include <stdexcept>

#include "read_factor.h"
#include "factor.h"
#include "iir.h"

// show factors
void show(const std::vector<double>& v);

// write properties of the transfer function
void comp_write(std::ostream& fout, const Freq& f, const std::vector<std::complex<double> >& v);

#endif
