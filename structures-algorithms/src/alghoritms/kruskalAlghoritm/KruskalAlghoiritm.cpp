#include "stdafx.h"
#include "KruskalAlghoiritm.h"
#include "structures\priorityQueue\PriorityQueue.h"
#include "structures\utilities\disjoinSet\DisjoinSet.h"

void KruskalAlghoiritm::printResult()
{
	int graphWeight = 0;
	cout << "Krawêdzie grafu rozpinaj¹cego: " << endl;
	for (int i = 0; i < m_resultList.getSize(); i++)
	{
		cout << m_resultList.getValue(i) << endl;
		graphWeight += m_resultList.getValue(i).getValue();
	}
	cout << "Suma wag krawêdzi: " << graphWeight << endl;

}

void KruskalAlghoiritm::apply(Graph * graph)
{
	DisjoinSet dj(m_currGraphSize);
	for (int i = 0; i < m_currGraphSize; i++)
		dj.makeSet(i);
	
	while (m_queue.getSize() != 0)
	{
		auto currEdge = m_queue.popElement();
		if (dj.findSet(currEdge.getStartName()) !=  dj.findSet(currEdge.getEndName()))
		{
			dj.makeUnion(currEdge.getStartName(), currEdge.getEndName());
			m_resultList.pushBack(currEdge);
		}
	}
}

void KruskalAlghoiritm::setParameters(int, int)
{
}

void KruskalAlghoiritm::prepare(Graph * graph)
{
	m_currGraphSize = graph->getAmountPoints();
	m_resultList.clearStructure();
	auto edges = graph->getEdges();
	m_queue.clearStructure();

	while (edges.getSize() != 0)
		m_queue.addElement(edges.popFrontElement());
}
