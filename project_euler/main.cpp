#include<iostream>
#include<chrono>

int main()
{
	auto startTime = std::chrono::steady_clock::now();
	

	auto elapsedTime = std::chrono::steady_clock::now() - startTime;
	std::cout << "Elapsed Time: " << elapsedTime.count() << std::endl;
	return 0;
}