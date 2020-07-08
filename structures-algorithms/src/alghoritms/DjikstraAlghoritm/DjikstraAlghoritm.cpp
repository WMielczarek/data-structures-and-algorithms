#include "stdafx.h"
#include "DjikstraAlghoritm.h"

using namespace std;

DjikstraAlghoritm::DjikstraAlghoritm()
{
	queue = make_shared<PriorityQueue<pointValueStructure>>();
}

DjikstraAlghoritm::~DjikstraAlghoritm()
{
	if (m_pathArray != nullptr)
		delete[] m_pathArray;

	if (m_distanceArray != nullptr)
		delete[] m_distanceArray;
}

void DjikstraAlghoritm::prepare(Graph * graph)
{
	queue->clearStructure();

	if (m_pathArray != nullptr)
		delete[] m_pathArray;

	if (m_distanceArray != nullptr)
		delete[] m_distanceArray;

	m_pathArray = new int[graph->getAmountPoints()];
	m_distanceArray = new int[graph->getAmountPoints()];

	// Set beginning values
	for (int i = 0; i < graph->getAmountPoints(); i++)
	{
		pointValueStructure pointStructure;
		if (i == startPoint)
			pointStructure.value = 0;

		pointStructure.point = i;
		m_distanceArray[i] = std::numeric_limits<int>::max();
		m_pathArray[i] =  -1;

		queue->addElement(pointStructure);
	}
	m_pathArray[startPoint] = -1;
	m_distanceArray[startPoint] = 0;

	currentGraphSize = graph->getAmountPoints();
}

void DjikstraAlghoritm::apply(Graph * graph)
{
	pointValueStructure currPointStruct;
	while (queue->getSize() != 0)
	{
		currPointStruct = queue->popElement();
				
		List<Edge> neighbours = graph->getNeighbours(currPointStruct.point);

		while (neighbours.getSize() != 0)
		{
			Edge currNeighbour = neighbours.popFrontElement();
			int neighbourIndex = queue->getIndex(pointValueStructure(currNeighbour.getEnd().getName()));

			if (queue->getSize() <= neighbourIndex || neighbourIndex < 0)
				continue;

			auto neighbourStruct = queue->popElement(neighbourIndex);

			if (neighbourStruct.value > currNeighbour.getValue() + currPointStruct.value || neighbourStruct.value == numeric_limits<int>::max())
			{
				neighbourStruct.value = currNeighbour.getValue() + currPointStruct.value;
				m_pathArray[currNeighbour.getEnd().getName()] = currPointStruct.point;
			}

			queue->addElement(neighbourStruct);
		}
		m_distanceArray[currPointStruct.point] = currPointStruct.value;
	}
}

void DjikstraAlghoritm::setParameters(int newStartPoint, int)
{
	startPoint = newStartPoint;
}

void DjikstraAlghoritm::printResult()
{
	List<int> displayer;

	cout << "Punkt startowy: " << startPoint << endl;
	cout << "Cel\tDystans\tTor" << endl;
	for (int i = 0; i < currentGraphSize; i++)
	{
		cout << i << "\t" << m_distanceArray[i] << "\t";
		auto pathFinder = i;
		while (pathFinder != -1)
		{
			displayer.pushFront(pathFinder);
			pathFinder = m_pathArray[pathFinder];
		}
		while (displayer.getSize() != 0)
			cout << displayer.popFrontElement() << " ";
		cout << endl;
	}
}

bool pointValueStructure::operator==(const pointValueStructure & e)
{
	return point == e.point;
}

bool pointValueStructure::operator<(const pointValueStructure & e)
{
	return value < e.value;
}

bool pointValueStructure::operator<=(const pointValueStructure & e)
{
	return *this < e || *this == e;
}

bool pointValueStructure::operator>(const pointValueStructure & e)
{
	return value > e.value;
}

bool pointValueStructure::operator>=(const pointValueStructure & e)
{
	return *this > e || *this == e;
}

bool pointValueStructure::operator!=(const pointValueStructure & e)
{
	return !((*this) == e);
}

std::ostream & operator<<(std::ostream & str, const pointValueStructure & s)
{
	if (s.value == std::numeric_limits<int>::max())
		str << "->" << s.point << "[infinity]";
	else
		str << "->" << s.point << "[" << s.value << "]";
	return str;
}
