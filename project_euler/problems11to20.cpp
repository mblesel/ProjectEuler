#include "problems11to20.h"
#include"helpfunctions.h"
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>

long long problem11()
{

	//reading the input into an Array
	//pretty ugly solution
	std::ifstream file("problem11input.txt", std::ios::in | std::ios::binary);

	char c;
	std::string inputString;
	while (file >> c)
	{
		if (c != ' ' && c != '\r')
		{
			inputString.push_back(c);
		}
	}

	int matrix[20][20];
	int x, y;
	x = y = 19;
		
	for (int i = 0; i < 400; ++i)
	{
		int a, b;

		b = inputString.back() - '0';
		inputString.pop_back();
		a = inputString.back() - '0';
		inputString.pop_back();
		
		matrix[x][y] = 10 * a + b;

		if (y == 0)
		{
			x--;
			y = 19;
		}
		else
		{
			y--;
		}
		
	}


	// solution to problem
	long long result = 0;

	//horizontal and 
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			long long product = matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3];

			if (product > result)
			{
				result = product;
			}

			product = matrix[j][i] * matrix[j + 1][i] * matrix[j + 2][i] * matrix[j + 3][i];
			if (product > result)
			{
				result = product;
			}
		}
	}

	//diagonal
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			long long product = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
			if (product > result)
			{
				result = product;
			}

			product = matrix[19-i][16-j] * matrix[18-i][17-j] * matrix[17-i][18-j] * matrix[16-i][19-j];
			if (product > result)
			{
				result = product;
			}
		}
	}

	return result;
}

int problem12()
{
	int triangleNumber = 1;
	int triangleValue = 1;

	while (numberOfDivisors(triangleValue) <= 500)
	{
		triangleNumber++;
		triangleValue += triangleNumber;
	}

	return triangleValue;
}

int problem14()
{
	int bestStartnumber = 1;
	int longestChain = 1;

	for (int i = 1; i < 1000000; i+=2)
	{
		int counter = 0;
		long long n = i;

		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n /= 2;
			}
			else
			{
				n = 3 * n + 1;
			}
			counter++;
		}

		if (counter > longestChain)
		{
			bestStartnumber = i;
			longestChain = counter;
		}
	}

	return bestStartnumber;
}