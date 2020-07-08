#include "stdafx.h"
#include "DisjoinSet.h"

DisjoinSet::DisjoinSet(const int & maxSize)
{
	m_array = new Node[maxSize];
	setSize = maxSize;
}


DisjoinSet::~DisjoinSet()
{
	delete[] m_array;
}

void DisjoinSet::makeSet(int toCreate)
{
	m_array[toCreate] = Node(toCreate);
}

void DisjoinSet::makeUnion(int setA, int setB)
{
	Node* nodeA = &m_array[findSet(setA)];
	Node* nodeB = &m_array[findSet(setB)];

	if (nodeA->id == nodeB->id)
		return;
	
	if (nodeA->rank >= nodeB->rank)
	{
		nodeA->rank = (nodeA->rank == nodeB->rank) ? nodeA->rank + 1 : nodeA->rank;
		nodeB->parent = nodeA;
	}
	else
		nodeA->parent = nodeB;
}

int DisjoinSet::findSet(int toFind) const
{
	Node* finder = &(m_array[toFind]);

	while (finder->parent != nullptr)
		finder = finder->parent;

	if(finder != &(m_array[toFind]))
		m_array[toFind].parent = finder;

	return finder->id;
}

int DisjoinSet::getSetRank(int set) const
{
	return m_array[findSet(set)].rank;
}

bool DisjoinSet::checkIntegration() const
{

	for (int i = 0; i < setSize; i++)
		for (int k = 0; k < setSize; k++)
			if (findSet(i) != findSet(k))
				return false;
	return true;
}

int DisjoinSet::getSetSize() const
{
	return setSize;
}

void DisjoinSet::print() const
{
	for (int i = 0; i < setSize; i++)
	{
		std::cout << i << " -> " << findSet(i) << std::endl;
	}
}
