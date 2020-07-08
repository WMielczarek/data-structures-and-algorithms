#include "stdafx.h"
#include "PrimAlghoritm.h"

PrimAlghoritm::~PrimAlghoritm()
{
	if (m_resultArray != nullptr)
		delete[] m_resultArray;
	if (m_outputGraph != nullptr)
		delete m_outputGraph;
}

void PrimAlghoritm::printResult()
{
	int graphSum = 0;
	for (int i = 0; i < m_currentGraphSize; i++)
		graphSum += m_resultArray[i].getValue();

	cout << "Lista krawêdzi: " << endl;
	for (int i = 1; i < m_currentGraphSize; i++)
		cout << m_resultArray[i] << endl;
	cout << "Waga grafu: " << graphSum << endl;
}

void PrimAlghoritm::apply(Graph * graph)
{
	bool firstIteration = true;
	while (m_queue.getSize() != 0)
	{
		auto currPoint = m_queue.popElement();
		auto currPointNeighboursList = graph->getNeighbours(currPoint.point);

		if (!firstIteration)
		{
			m_outputGraph->addEdge(m_resultArray[currPoint.point]);
		}
		else
			firstIteration = false;

		while(currPointNeighboursList.getSize() != 0)
		{
			auto neighbourFromList = currPointNeighboursList.popFrontElement();
			auto currNeghbourIndex = m_queue.getIndex(pointValueStructure(neighbourFromList.getEndName()));

			//Not found in queue
			if (currNeghbourIndex == -1)
				continue;

			auto neighbourFromQueue = m_queue.popElement(currNeghbourIndex);
			
			if (neighbourFromQueue.value > neighbourFromList.getValue())
			{
				neighbourFromQueue.value = neighbourFromList.getValue();
				m_resultArray[neighbourFromList.getEndName()] = neighbourFromList;
			}

			m_queue.addElement(neighbourFromQueue);
		}
	}
}

//This alghoritm doesn't have additional parameters
void PrimAlghoritm::setParameters(int, int)
{}


void PrimAlghoritm::prepare(Graph * graph)
{
	m_currentGraphSize = graph->getAmountPoints();

	m_queue.clearStructure();
	if (m_resultArray != nullptr)
		delete[] m_resultArray;
	m_resultArray = new Edge[m_currentGraphSize];

	for (int i = 0; i < m_currentGraphSize; i++)
	{
		if (i == 0)
			m_queue.addElement(pointValueStructure(0, 0));
		else
			m_queue.addElement(pointValueStructure(i));
	}

	if (m_outputGraph != nullptr)
		delete m_outputGraph;

	if (outputSetting == AlghoritmOutputSetting::list)
		m_outputGraph = new ListGraph;
	else
		m_outputGraph = new MatrixGraph;

	m_outputGraph->resize(m_currentGraphSize);
}

int PrimAlghoritm::whoIntroduced(int a) const
{
	return m_resultArray[a].getStartName();
}
