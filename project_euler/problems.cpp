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