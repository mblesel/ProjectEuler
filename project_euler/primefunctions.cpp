#include"primefunctions.h"
#include<cmath>

bool isPrime(long n)
{
	for (long i = 2; i <= std::sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}