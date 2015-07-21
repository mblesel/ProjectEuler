#include"helpfunctions.h"
#include<cmath>
#include<string>

bool isPrime(int n)
{
	if (n == 2)
	{
		return true;
	}

	for (int i = 3; i <= std::sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}


bool isPalindrome(int n)
{
	auto forward = std::to_string(n);
	auto backwards = std::string(std::rbegin(forward), std::rend(forward));

	return forward == backwards;
}

