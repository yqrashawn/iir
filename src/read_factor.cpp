#include "read_factor.h"

using namespace std;

void read_factor(ifstream& fin, Freq& f, vector<double>& fa, vector<double>& fb)
{
  string s;
  while (getline(fin, s)) {
    if (s.find("%") == string::npos) {
      // input frequency range and count
      if(s.find("begin") != string::npos)       f.begin = input_factor(s);
      else if (s.find("end") != string::npos)   f.end   = input_factor(s);
      else if (s.find("count") != string::npos) f.count = input_factor(s);
      // input factor
      else if (s.find("a") != string::npos) input_factor(fa, s);
      else if (s.find("b") != string::npos) input_factor(fb, s);
    }
  }
  if ( f.begin > f.end ) throw out_of_range("error: 'begin' must be less than 'end'.");
  if ( f.count <= 0 ) throw out_of_range("error: 'count' must be greater than 0.");
  if( fa.empty() || fb.empty() ) throw invalid_argument("error: Factors not found.");
}
double input_factor (const string& s)
{
  auto i = find_if(s.begin(), s.end(), isNumber);
  if (i != s.end()) {
    const string tmp(i, s.end());
    return atof(tmp.c_str());
  } else
    throw invalid_argument("error: Invalid factor error.");
}
void input_factor (vector<double>& f, const string& s)
{
  auto i = num_beg(s.begin(), s.end());
  if (i != s.end()) {
    const string tmp(i, s.end());
    const double num = atof(tmp.c_str());
    f.push_back(num);
  } else
    throw invalid_argument("error: Invalid factor error.");
}
string::const_iterator
num_beg( string::const_iterator b, string::const_iterator e)
{
  auto i = find_if(b, e, isNumber);
  if (i != e) {
    i = find_if(++i, e, isNumber);
    if(i != e) return i;
    else return e;
  } else return e;
}
int isNumber(const char c)
{
  return isdigit(c) || c == '-';
}
