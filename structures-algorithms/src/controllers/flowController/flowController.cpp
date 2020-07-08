#include "stdafx.h"
#include "flowController.h"
#include "views\flow\FlowMenu.h"
#include "alghoritms\fordFulkersonAlghoritm\FordFulkersonAlghoritm.h"

flowController::flowController()
{
	init();
}

void flowController::handleAdditionalParameters(const std::string &input)
{
	istringstream iss(input);
	// 1st and 2nd is amount of points and edges
	iss >> amountOfEdges;
	iss >> amountOfPoints;
	iss >> m_startPoint;
	iss >> m_endPoint;

	m_matrix.resize(amountOfPoints);
	m_list.resize(amountOfPoints);
}

void flowController::parseEdgeString(const std::string &edgeString)
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

void flowController::parseInput(const std::string & input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	FordFulkersonAlghoritm* alghoritm = new FordFulkersonAlghoritm;

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
		alghoritm->setMode(false);

		cout << "Dla macierzy: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::matrix);
		alghoritm->setParameters(m_startPoint, m_endPoint);
		alghoritm->apply(&m_matrix);
		alghoritm->printResult();

		cout << endl;

		cout << "Dla listy s¹siadów: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::list);
		alghoritm->setParameters(m_startPoint, m_endPoint);
		alghoritm->apply(&m_list);
		alghoritm->printResult();
		system("pause");
		break;
	case 3:
		alghoritm->setMode(true);

		cout << "Dla macierzy: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::matrix);
		alghoritm->setParameters(m_startPoint, m_endPoint);
		alghoritm->apply(&m_matrix);
		alghoritm->printResult();

		cout << endl;

		cout << "Dla listy s¹siadów: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::list);
		alghoritm->setParameters(m_startPoint, m_endPoint);
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

void flowController::init()
{
	view = make_unique<FlowMenu>();
}
