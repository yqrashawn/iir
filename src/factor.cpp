#include "factor.h"

Freq::Freq()
{
  begin = 0; end = 1; count = 0.001;
}
Freq::Freq(double a, double b, double c)
{
  begin = a; end = b; count = c;
}
