#include "stdafx.h"
#include "GenericProblemController.h"
#include "structures\utilities\disjoinSet\DisjoinSet.h"

using namespace std;

void GenericProblemController::loadFromFile()
{
	string userInput = "";
	string line = "";

	cout << "Podaj nazwê pliku: ";
	cin >> userInput;
	m_list.clear();
	m_matrix.clear();

	ifstream fileStream(userInput);

	if (!fileStream.is_open())
	{
		cout << "Nie mo¿na otworzyæ pliku. " << endl;
		system("pause");
		return;
	}

	getline(fileStream, line);
	handleAdditionalParameters(line);

	while (getline(fileStream, line))
	{
		if (!line.empty())
			parseEdgeString(line);
	}
}

void GenericProblemController::parseEdgeString(const string &line)
{
	istringstream iss(line);
	int startPoint, endpoint, edgeValue;
	iss >> startPoint;
	iss >> endpoint;
	iss >> edgeValue;
	Point start(startPoint);
	Point end(endpoint);
	Edge edge(edgeValue, start, end);

	m_matrix.addPoint(start);
	m_matrix.addPoint(end);

	m_list.addPoint(start);
	m_list.addPoint(end);

	m_matrix.addEdge(edge);
	m_list.addEdge(edge);

}

void GenericProblemController::print()
{
	std::cout << "Reprezentacja macierzowa: " << std::endl;
	m_matrix.print();
	std::cout << "\nReprezentacja listowa\n";
	m_list.print();
}

void GenericProblemController::generateGraph(int density, int vertex, int range, int baseValue, bool directed)
{
	m_matrix.clear();
	m_list.clear();

	m_matrix.resize(vertex);
	m_list.resize(vertex);

	DisjoinSet dj(vertex);

	for (int i = 0; i < vertex; i++)
		dj.makeSet(i);

	while (m_matrix.getDensity() < density)
	{
		Edge e(rand()%range + baseValue, rand()%vertex, rand() % vertex, directed);

		if (m_matrix.getEdgeValue(e.getStartName(), e.getEndName()) != 0 || e.getEndName() == e.getStartName())
			continue;
		m_matrix.addEdge(e);
		m_list.addEdge(e);
		dj.makeUnion(e.getStartName(), e.getEndName());
	}

	//Check if no vertexes are not connected
	if(!dj.checkIntegration())
		for (int i = 0; i < dj.getSetSize(); i++)
			for (int k = 0; k < dj.getSetSize(); k++)
				if (dj.findSet(i) != dj.findSet(k))
				{
					Edge e(rand() % range + baseValue, i, k, directed);
					m_matrix.addEdge(e);
					m_list.addEdge(e);
				}

}
