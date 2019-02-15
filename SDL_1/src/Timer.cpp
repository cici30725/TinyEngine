#include "pch.h"
#include "Timer.h"


Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::Init() {
	tp1 = std::chrono::system_clock::now();
	tp2 = std::chrono::system_clock::now();
}


float Timer::GetElapsedTime() {
	tp2 = std::chrono::system_clock::now();
	std::chrono::duration<float> elapsedTime = tp2 - tp1;
	tp1 = tp2;
	float fElapsedTime = elapsedTime.count();
	return fElapsedTime;
}
