#include<iostream>
#include<chrono>

#include"problems.h"
#include"StopWatch.h"

int main()
{
	StopWatch<std::chrono::milliseconds> clock;
	
	clock.start();
	
	std::cout << problem1() << std::endl;

	std::cout << "Elapsed Time: " << clock.stop() << "ms";

	return 0;
}