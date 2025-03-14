#include "bmath.h"

int babs(int a)
{
	int mask = a >> 31;
	return (a ^ mask) - mask;
}

int b_sqrt(int n)
{
	if (n <= 0) return 0;
	double x = (double)n;

	for (int i = 0; i < 10; i++)
		x = (x + (double)n / x) / 2.0;
	return (int)(x + 0.5);

}