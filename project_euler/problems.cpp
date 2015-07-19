#include"problems.h"

#include<iostream>

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


	return 0;

}