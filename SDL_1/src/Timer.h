#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	~Timer();
	void Init();
	float GetElapsedTime();
private:
	std::chrono::time_point<std::chrono::system_clock> tp1;
	std::chrono::time_point<std::chrono::system_clock> tp2;
};

