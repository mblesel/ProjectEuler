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
	auto backwards = std::string(forward.rbegin(), forward.rend());

	return forward == backwards;
}

int numberOfDivisors(int n)
{
	if (n < 1)
	{
		return -1;
	}
	else if (n == 1)
	{
		return 1;
	}

	//initialize with the ovious divisors 1 and n
	int divisors = 2;

	for (int i = 2; i < std::sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			divisors+=2;
		}
	}

	return divisors;
}
