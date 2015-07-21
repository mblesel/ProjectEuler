#include"problems1to10.h"

#include"helpfunctions.h"

#include<cmath>
#include<fstream>
#include<iostream>
#include<string>
#include<numeric>
#include<functional>
#include<bitset>
#include<vector>

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


int problem2()
{
	int first = 1;
	int second = 2;
	int next = first + second;
	int result = 2;

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


int problem3()
{
	long long number = 600851475143;

	for (int i = static_cast<int>(std::sqrt(number)); i > 1; --i)
	{
		if ((number % i == 0 ) && isPrime(i))
		{
			return i;
		}
	}

	return 0;

}


int problem4()
{
	int result = 0;

	for (int i = 999; i > 900; --i)
	{
		for (int j = 999; j > 900; --j)
		{
			int product = i*j;
			if (isPalindrome(product) && product > result)
			{
				result = product;
			}
		}
	}

	return result;
}

int problem5()
{
	for (int i = 20 * 19;; ++i)
	{
		if (i % 2 == 0 && i % 19 == 0 && i % 18 == 0 && i % 17 == 0 &&
			i % 16 == 0 && i % 15 == 0 && i % 14 == 0 && i % 13 == 0 &&
			i % 12 == 0 && i % 11 == 0 && i % 20 == 0)
		{
			return i;
		}
	}
}

int problem6()
{
	int squaresum = 0;
	int sum = 0;

	for (int i = 1; i <= 100; ++i)
	{
		squaresum += i*i;
		sum += i;
	}

	return (sum * sum - squaresum);
}

int problem7()
{
	int primecounter = 1;
	int primecandidate = 3;

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

int problem9()
{
	int a, b, c;

	for (c = 1; c < 1000; ++c)
	{
		for (a = 1; a < 1000; ++a)
		{
			b = 1000 - c - a;

			if (a*a + b*b == c*c)
			{
				return a*b*c;
			}
		}
	}

}


long long problem10()
{
	std::bitset<2000000> sieve;

	sieve[0].flip();
	sieve[1].flip();

	int p = 2;

	while (p < 2000000)
	{
		for (int i = 1; p+2*p*i < 2000000; ++i)
		{
			sieve.set(p+2*p*i, 1);
		}

		do
		{
			p++;

		} while (p < 2000000 && sieve.test(p));
	}

	long long result = 2;

	for (int i = 3; i < 2000000; i += 2)
	{
		if (!sieve.test(i))
		{
			result += i;
		}
	}

	return result;
}
