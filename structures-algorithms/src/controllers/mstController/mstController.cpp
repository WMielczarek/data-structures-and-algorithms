#include "stdafx.h"
#include "mstController.h"
#include "views\mst\mstMenu.h"
#include "alghoritms\kruskalAlghoritm\KruskalAlghoiritm.h"
#include "alghoritms\primAlghoritm\PrimAlghoritm.h"

mstController::mstController()
{
	init();
}

void mstController::handleAdditionalParameters(const std::string &input)
{
	istringstream iss(input);
	// 1st and 2nd is amount of points and edges
	iss >> amountOfEdges;
	iss >> amountOfPoints;

	m_matrix.resize(amountOfPoints);
	m_list.resize(amountOfPoints);
}

void mstController::parseEdgeString(const std::string &edgeString)
{
	int startPoint, endPoint, value;
	istringstream iss(edgeString);
	// 1st and 2nd is amount of points and edges
	iss >> startPoint;
	iss >> endPoint;
	iss >> value;

	Edge e(value, Point(startPoint), Point(endPoint));
	e.setDirected(false);
	m_matrix.addEdge(e);
	m_list.addEdge(e);
}

void mstController::parseInput(const std::string & input)
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
		alghoritm = new KruskalAlghoiritm;

		cout << "Dla macierzy: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::matrix);
		alghoritm->prepare(&m_matrix);
		alghoritm->apply(&m_matrix);
		alghoritm->printResult();

		cout << endl;

		cout << "Dla listy s¹siadów: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::list);
		alghoritm->prepare(&m_list);
		alghoritm->apply(&m_list);
		alghoritm->printResult();
		system("pause");



		break;
	case 3:
		alghoritm = new PrimAlghoritm;

		cout << "Dla macierzy: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::matrix);
		alghoritm->prepare(&m_matrix);
		alghoritm->apply(&m_matrix);
		alghoritm->printResult();

		cout << endl;

		cout << "Dla listy s¹siadów: " << endl;
		alghoritm->setOuputType(AlghoritmOutputSetting::list);
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

		generateGraph(density, vertexes, range, startValue, false);
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

void mstController::init()
{
	view = make_unique<mstMenu>();
}
