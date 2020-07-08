#pragma once

#include "stdafx.h"
#include "views/genericView/GenericView.h"
class GenericController
{
public:
	GenericController() : running(false) {};
	virtual ~GenericController() = default;
	virtual void parseInput(const std::string &input);
	virtual void printView();

	bool isRunning();
	void Run();
	void Stop();

	std::unique_ptr<GenericView> view;
protected:
	virtual void init() = 0;

private:
	bool running;
};

