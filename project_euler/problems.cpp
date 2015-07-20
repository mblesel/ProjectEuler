#include"problems.h"

#include"helpfunctions.h"

#include<cmath>
#include<fstream>
#include<iostream>
#include<string>
#include<numeric>
#include<functional>

int problem1()
{
	int res = 0;

	for (int i = 3; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			res += i;
		}
	}

	return res;
}


long problem2()
{
	int first = 1;
	int second = 2;
	int next = first + second;
	long result = 2;

	while (next <= 4000000)
	{
		if (next % 2 == 0)
		{
			result += next;
		}

		first = second;
		second = next;
		next = first + second;
	}

	return result;
}


long problem3()
{
	long long number = 600851475143;

	for (long i = static_cast<long>(std::sqrt(number)); i > 1; --i)
	{
		if ((number % i == 0 ) && isPrime(i))
		{
			return i;
		}
	}

	return 0;

}


long problem4()
{
	long result = 0;

	for (int i = 999; i > 900; --i)
	{
		for (int j = 999; j > 900; --j)
		{
			long product = i*j;
			if (isPalindrome(product) && product > result)
			{
				result = product;
			}
		}
	}

	return result;
}

long problem5()
{
	for (long i = 20 * 19;; ++i)
	{
		if (i % 2 == 0 && i % 19 == 0 && i % 18 == 0 && i % 17 == 0 &&
			i % 16 == 0 && i % 15 == 0 && i % 14 == 0 && i % 13 == 0 &&
			i % 12 == 0 && i % 11 == 0 && i % 20 == 0)
		{
			return i;
		}
	}
}

long problem6()
{
	long squaresum = 0;
	long sum = 0;

	for (int i = 1; i <= 100; ++i)
	{
		squaresum += i*i;
		sum += i;
	}

	return (sum * sum - squaresum);
}

long problem7()
{
	int primecounter = 1;
	long primecandidate = 3;

	while (primecounter < 10001)
	{
		if (isPrime(primecandidate))
		{
			primecounter++;
		}
		primecandidate += 2;
	}

	return primecandidate - 2;
}

long long problem8()
{
	//reading the 1000digit Number from file
	std::ifstream inputfile;
	inputfile.open("problem8input.txt");

	std::string bigNumber;

	if (inputfile.is_open())
	{
		std::string temp;
		while (std::getline(inputfile, temp))
		{
			bigNumber += temp;
		}
	}

	const int DIGITS = 13;

	long long result = 0;

	for (int i = 0; i < bigNumber.size() - DIGITS; ++i)
	{
		std::string substr = bigNumber.substr(i, i + DIGITS);

		long long  temp = 1;

		for (int j = 0; j < DIGITS; ++j)
		{
			temp *= substr[j] - '0';
		}

		if (temp > result)
		{
			result = temp;
		}

	}

	return result;
}

long problem9()
{
	return 0;
}