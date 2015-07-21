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

	std::vector<int> chainlengths(1000000, 0);

	for (int i = 1; i < 1000000; i+=2)
	{
		int counter = 0;
		long long n = i;

		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n /= 2;

				if (n < i)
				{
					if (chainlengths[n] != 0)
					{
						counter += chainlengths[n] + 1;
						break;
					}
				}
			}
			else
			{
				n = 3 * n + 1;
			}
			counter++;
		}

		chainlengths[i] = counter;

		if (counter > longestChain)
		{
			bestStartnumber = i;
			longestChain = counter;
		}
	}

	return bestStartnumber;
}

long long f(int x, int y, int XLIMIT, int YLIMIT, long long matrix[21][21])
{
	if (matrix[x][y] > 0)
	{
		return matrix[x][y];
	}


	if (x < XLIMIT && y < YLIMIT )
	{
		return f(x + 1, y, XLIMIT, YLIMIT, matrix) + f(x, y + 1, XLIMIT, YLIMIT, matrix);
	}
	else if (x < XLIMIT)
	{
		return f(x + 1, y, XLIMIT, YLIMIT, matrix);
	}
	else if (y < YLIMIT)
	{
		return f(x, y + 1, XLIMIT, YLIMIT, matrix);
	}
	else
	{
		return 1;
	}

}

long long problem15()
{
	const int N = 20;
	long long matrix[N+1][N+1];
	
	matrix[2][2] = 0;
	matrix[1][1] = 2;

	for (int i = N; i >= 0; --i)
	{
		for (int j = N; j >= 0; --j)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = N; i >= 0; --i)
	{
		for (int j = N; j >= 0; --j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = f(i, j, N, N, matrix);
			}
		}
	}

	return matrix[0][0];
	
}