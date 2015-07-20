#include"helpfunctions.h"
#include<cmath>
#include<string>

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


bool isPalindrome(long n)
{
	auto forward = std::to_string(n);
	auto backwards = std::string(std::rbegin(forward), std::rend(forward));

	return forward == backwards;
}