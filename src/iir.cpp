#include "iir.h"

using namespace std;

void iir (vector<complex<double> >& v, const Freq& f, const vector<double>& a, const vector<double>& b)
{
	for (double i = f.begin; i <= f.end; i += f.count)
		v.push_back( iir_calc(freq_to_z(i), a, b) );
}
complex<double> freq_to_z(const double f)
{
	return polar(1.0, M_PI * f);
}
complex<double>
iir_calc(const complex<double> z, const vector<double>& a, const vector<double>& b)
{
	complex<double> num, den(1.0, 0.0);
	vector<double>::size_type i;
  double n = 0;
  for (i = 0; i != a.size(); ++i, ++n) {
		num += a[i] * pow(z, -n);
	}
	for (i = 1, n = 1; i != b.size(); ++i, ++n) {
		den += b[i] * pow(z, -n);
	}
	return num/den;
}
void arg_group_delay (vector<double>& a, vector<double>& d, const vector<complex<double> >& v, const double df)
{
  // phase
	for (decltype(v.size()) i = 0; i != v.size(); ++i) {
		a.push_back( arg(v[i]) );
		// phase unwrapping
		double tmp = a[i];
		if (i) {
			const double t = abs(a[i] - a[i-1]);
			const double ratio = floor(t/3.0);
			if ( t >= 3 ) {
				if (a[i] > a[i-1] ) tmp -= M_PI * ratio;
				else if (a[i] < a[i-1] ) tmp += M_PI * ratio;
			}
		}
		a[i] = tmp;
	}
  // group delay
  const double dw = M_PI * df;
	for (decltype(a.size()) j = 0; j < a.size() - 1; ++j)
		d.push_back( -1 * (a[j + 1] - a[j]) / dw);

	d.push_back( d[a.size() - 2] );
}
