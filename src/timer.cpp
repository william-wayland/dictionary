#include "timer.h"

void Timer::start_recording()
{
    if (recording)
    {
        std::cerr << "Was Already Recording." << '\n';
    }
    else
    {
        start = std::chrono::high_resolution_clock::now();
        recording = true;
    }
}

double Timer::end_recording()
{
    if (!recording)
    {
        std::cerr << "Wasn't Recording." << '\n';
    }
    else
    {
        finish = std::chrono::high_resolution_clock::now();
        recording = false;
        std::chrono::duration<double> result = finish - start;
        return result.count();
    }
    return 0.0;
}
