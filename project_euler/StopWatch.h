#include<chrono>

template<typename TimeT=std::chrono::milliseconds>
class StopWatch
{
private:
	std::chrono::steady_clock::time_point _start, _stop;

public:
	StopWatch(){}

	void start(){
		_start = std::chrono::steady_clock::now(); 
	}
	
	double stop(){
		_stop = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<TimeT>(_stop - _start).count();
	}
};