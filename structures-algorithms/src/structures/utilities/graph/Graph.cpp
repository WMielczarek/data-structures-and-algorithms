#include "stdafx.h"
#include "Graph.h"
#include "structures\utilities\disjoinSet\DisjoinSet.h"

int Graph::getAmountPoints()
{
	return m_amountPoints;
}

int Graph::getDensity()
{
	int maxEdgeAmount = m_amountPoints*(m_amountPoints - 1);;
	int amountOfEdges = m_amountEdges;
	if (!isDirected)
	{
		maxEdgeAmount /= 2;
		amountOfEdges /= 2;
	}

	return (int)((((float)amountOfEdges)/((float)maxEdgeAmount))*100);
}

int Graph::getAmountEdges()
{
	return m_amountEdges;
}

Point Graph::getRandomPoint()
{
	return Point(rand() % this->getAmountPoints());
}

void Graph::generate(int density, int vertex, int range, int baseValue, bool directed)
{
	clear();
	resize(vertex);

	DisjoinSet dj(vertex);

	for (int i = 0; i < vertex; i++)
		dj.makeSet(i);

	while (getDensity() < density)
	{
		Edge e(rand() % range + baseValue, rand() % vertex, rand() % vertex, directed);

		if (getEdgeValue(e.getStartName(), e.getEndName()) != 0 || e.getEndName() == e.getStartName())
			continue;
		addEdge(e);
		dj.makeUnion(e.getStartName(), e.getEndName());
	}

	//Check if no vertexes are not connected
	if (!dj.checkIntegration())
		for (int i = 0; i < dj.getSetSize(); i++)
			for (int k = 0; k < dj.getSetSize(); k++)
				if (dj.findSet(i) != dj.findSet(k))
				{
					Edge e(rand() % range + baseValue, i, k, directed);
					addEdge(e);
				}

}
