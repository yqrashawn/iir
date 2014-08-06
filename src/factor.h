#ifndef _FACTOR_H
#define _FACTOR_H

class Freq
{
public:
	double begin;         // starting freq
	double end;           // ending freq
	double count;         // sampling interval

	Freq();
	Freq(double a, double b, double c);
};

#endif
