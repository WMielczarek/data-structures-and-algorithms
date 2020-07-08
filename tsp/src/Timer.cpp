#include "Timer.h"

LARGE_INTEGER Timer::getTime() {
	LARGE_INTEGER tmp;

	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&tmp);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);

	return tmp;
}

Timer::Timer() {
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	frequency = double(freq.QuadPart) / 1000;
}

void Timer::start() {
	startTime = getTime();
}

double Timer::end() {
	return (getTime().QuadPart - startTime.QuadPart) / frequency;
}