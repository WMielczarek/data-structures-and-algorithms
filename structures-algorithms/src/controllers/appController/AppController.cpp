#if defined(max);
	#undef max;
	#else
#endif

#include "stdafx.h"
#include "AppController.h"
#include "views\app\appMenu.h"

#include "controllers\sppController\sppController.h"
#include "controllers\mstController\mstController.h"
#include "controllers\flowController\flowController.h"
#include "controllers\testControllers\genericTestController\genericTestController.h"
#include "controllers\testControllers\Tester.h"


using namespace std;

AppController::AppController() : GenericController()
{
	setlocale(LC_ALL, "Polish");
}

void AppController::parseInput(const std::string &input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	switch (parsedInput) 
	{
		case 0:
			this->Stop();
			break;
		case 1:
			controller = std::make_unique<mstController>();
			controller->Run();
			break;
		case 2:
			controller = std::make_unique<sppController>();
			controller->Run();
			break;
		case 3:
			controller = std::make_unique<flowController>();
			controller->Run();
			break;
		case 4:
			runTests();
			break;
		default:
			throw new std::invalid_argument("Unknown controller input");
			break;
	}
}


void AppController::init()
{
	view = std::make_unique<appMenu>();
	srand((unsigned int)time(NULL));
}

void AppController::runTests()
{
	Tester t;
	t.runAllTests();
}
