#include "stdafx.h"
#include "sppController.h"
#include "alghoritms\DjikstraAlghoritm\DjikstraAlghoritm.h"
#include "alghoritms\bfAlghoritm\bfAlghoritm.h"
#include "views\spp\sppMenu.h"

using namespace std;

sppController::sppController()
{
	init();
}

void sppController::init()
{
	view = make_unique<sppMenu>();
}

void sppController::parseInput(const std::string & input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	IAlghoritm* alghoritm = nullptr;

	system("cls");
	switch (parsedInput)
	{
	case 0:
		this->Stop();
		break;
	case 1:
		loadFromFile();
		break;
	case 2:
		alghoritm = new DjikstraAlghoritm;
		alghoritm->setParameters(startPoint, 0);

		cout << "Dla macierzy: " << endl;
		alghoritm->prepare(&m_matrix);
		alghoritm->apply(&m_matrix);
		alghoritm->printResult();

		cout << "Dla listy s¹siadów: " << endl;
		alghoritm->prepare(&m_list);
		alghoritm->apply(&m_list);
		alghoritm->printResult();
		system("pause");
		break;
	case 3:
		alghoritm = new bfAlghoritm;
		alghoritm->setParameters(startPoint, 0);

		cout << "Dla macierzy: " << endl;
		alghoritm->prepare(&m_matrix);
		alghoritm->apply(&m_matrix);
		alghoritm->printResult();

		cout << "Dla listy s¹siadów: " << endl;
		alghoritm->prepare(&m_list);
		alghoritm->apply(&m_list);
		alghoritm->printResult();
		system("pause");
		break;
	case 4:
		system("cls");
		int vertexes, density, range, startValue;

		cout << "Iloœæ wiecho³ków: ";
		cin >> vertexes;
		cout << endl;

		cout << "Gêstoœæ grafu: ";
		cin >> density;
		cout << endl;

		cout << "Wartoœæ pocz¹tkowa: ";
		cin >> startValue;
		cout << endl;

		cout << "Zakres wartoœci: ";
		cin >> range;
		cout << endl;

		generateGraph(density, vertexes, range, startValue, true);
		break;
	case 5:
		cout << "Lista s¹siadów: " << endl;
		m_list.print();
		cout << endl;
		cout << "Macierz s¹siedztwa: " << endl;
		m_matrix.print();
		cout << endl;
		system("pause");
		break;
	default:
		throw std::invalid_argument("Unknown controller input");
		break;
	}

	if (alghoritm != nullptr)
		delete alghoritm;

	system("cls");
}

void sppController::parseEdgeString(const std::string & edgeString)
{
	int startPoint, endPoint, value;
	istringstream iss(edgeString);
	// 1st and 2nd is amount of points and edges
	iss >> startPoint;
	iss >> endPoint;
	iss >> value;

	Edge e(value, Point(startPoint), Point(endPoint));
	e.setDirected(true);
	m_matrix.addEdge(e);
	m_list.addEdge(e);
}

void sppController::handleAdditionalParameters(const std::string & parametesString)
{
	istringstream iss(parametesString);
	// 1st and 2nd is amount of points and edges
	iss >> amountOfEdges;
	iss >> amountOfPoints;
	iss >> startPoint;

	m_matrix.resize(amountOfPoints);
	m_list.resize(amountOfPoints);
}
