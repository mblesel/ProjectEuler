#include<iostream>
#include<chrono>

#include"problems1to10.h"
#include"StopWatch.h"

int main()
{
	StopWatch<std::chrono::milliseconds> clock;
	
	clock.start();
	
	std::cout << "Result: " << problem10() << std::endl;

	std::cout << "Elapsed Time: " << clock.stop() << "ms";

	return 0;
}