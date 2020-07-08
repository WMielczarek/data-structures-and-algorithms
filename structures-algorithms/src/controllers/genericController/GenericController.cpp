#include "stdafx.h"
#include "GenericController.h"

using namespace std;

void GenericController::parseInput(const std::string & input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	system("cls");
	switch (parsedInput)
	{
	case 0:
		this->Stop();
		break;
	default:
		throw std::invalid_argument("Unknown controller input");
		break;
	}
	system("cls");
}

void GenericController::printView()
{
	view->print();
}


void GenericController::Run()
{
	init();
	running = true;
	string userInput;
	do {
		system("cls");
		this->printView();
		cout << "Podaj opcję: " << endl;
		cin >> userInput;

		try
		{
			this->parseInput(userInput);
		}
		catch (invalid_argument& e)
		{
			cout << "Nieprawidłowy argument" << endl;
			cout << e.what();
			system("pause");
		}
	} while (this->isRunning());
}

void GenericController::Stop()
{
	running = false;
}

bool GenericController::isRunning()
{
	return running;
}
