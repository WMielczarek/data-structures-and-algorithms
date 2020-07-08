#pragma once

#include <Windows.h>

class Timer {
	LARGE_INTEGER startTime;
	double frequency;

	LARGE_INTEGER getTime();

public:
	Timer();

	void start();
	double end();
};