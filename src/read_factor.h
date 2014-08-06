#ifndef _READ_FACTOR_H
#define _READ_FACTOR_H

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

#include "factor.h"

void read_factor(std::ifstream& fin, Freq& f, std::vector<double>& fa, std::vector<double>& fb);
std::string::const_iterator
num_beg(std::string::const_iterator b, std::string::const_iterator e);

double input_factor (const std::string& s);
void input_factor (std::vector<double>& f, const std::string& s);

int isNumber(const char c);

#endif