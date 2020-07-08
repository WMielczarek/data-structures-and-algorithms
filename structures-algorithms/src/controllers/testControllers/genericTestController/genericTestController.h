#pragma once

#include "stdafx.h"


class genericTestController
{
public:
	genericTestController() = default;
	virtual ~genericTestController() = default;

	virtual void runAllTests() = 0;

protected:
	virtual void saveToFile(int testSize, int time);
	virtual void saveToFile(std::string message);

	std::string filename;

private:
	std::ofstream file;
};

