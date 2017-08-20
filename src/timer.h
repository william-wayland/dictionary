#include <chrono>
#include <iostream>

class Timer
{
private:
	 std::chrono::high_resolution_clock::time_point start, finish;
	 bool recording = false;
public:
    Timer() = default;
    ~Timer() = default;
	void start_recording();
	double end_recording();
};
