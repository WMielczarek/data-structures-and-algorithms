#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
#include "stdafx.h"

class AppController :
	public GenericController
{
	public:
		AppController();
		virtual ~AppController() = default;
		virtual void parseInput(const std::string &input);

		virtual void init();	
	private:
		void runTests();
		std::unique_ptr<GenericController> controller;
};

