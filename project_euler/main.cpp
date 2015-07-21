#include<iostream>
#include<chrono>

#include"problems1to10.h"
#include"problems11to20.h"
#include"StopWatch.h"

int main()
{
	StopWatch<std::chrono::milliseconds> clock;
	
	clock.start();
	
	std::cout << "Result: " << problem15() << std::endl;

	std::cout << "Elapsed Time: " << clock.stop() << "ms";

	return 0;
}