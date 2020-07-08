#include "stdafx.h"
#include "MatrixGraph.h"


#include "structures\array\Array.h"
#include "structures\list\List.h"

MatrixGraph::MatrixGraph()
{
	m_matrix.resize(0);
}

MatrixGraph::MatrixGraph(MatrixGraph & m)
{
	resize(m.getAmountPoints());

	for(int i = 0; i < getAmountPoints(); i++)
		for (int j = 0; j < getAmountPoints(); j++)
		{
			auto edge = m.getEdge(i, j);
			if (edge == nullptr)
				m_matrix.setValue(i, j, 0);
			else
				m_matrix.setValue(i, j, edge->getValue());
		}
}

void MatrixGraph::clear()
{
	m_matrix.resize(0);
	m_amountEdges = 0;
	m_amountPoints = 0;
}

void MatrixGraph::addEdge(const Edge &e)
{
	if (m_matrix.getSize() <= e.getStart().getName() || m_matrix.getSize() <= e.getEnd().getName())
	{
		m_matrix.resize((e.getEnd().getName() > e.getStart().getName()) ? e.getEnd().getName() : e.getStart().getName());
	}

	m_matrix.setValue(e.getStart().getName(), e.getEnd().getName(), e.getValue());
	m_amountEdges++;
	if (!(e.isDirected()))
	{
		m_matrix.setValue(e.getEnd().getName(), e.getStart().getName(), e.getValue());
		m_amountEdges++;
		isDirected = false;
	}
}

void MatrixGraph::addPoint(const Point &p)
{
	m_matrix.resize(m_matrix.getSize() + 1);

	for (int i = 0; i < m_matrix.getSize(); i++)
	{
		m_matrix.setValue(m_matrix.getSize() - 1, i, 0);
		m_matrix.setValue(i, m_matrix.getSize() - 1, 0);
	}
	m_amountPoints++;
}

shared_ptr<Edge> MatrixGraph::getEdge(int a, int b)
{
	if (m_matrix.getValue(a, b) == 0)
		return nullptr;
	else
		return make_shared<Edge>(m_matrix.getValue(a, b), a, b);
}

List<Edge> MatrixGraph::getEdges()
{
	List<Edge> output;

	if (isDirected)
	{
		for (int i = 0; i < getAmountPoints(); i++)
		{
			auto neighbourList = getNeighbours(i);
			while (neighbourList.getSize() != 0)
				output.addElement(neighbourList.popFrontElement());
		}
	}
	else
	{
		for (int i = 0; i < getAmountPoints(); i++)
			for (int j = 0; j <= i; j++)
				if (m_matrix.getValue(i, j) != 0)
					output.addElement(Edge(m_matrix.getValue(i, j), i, j));
	}

	return output;
}

List<Edge> MatrixGraph::getNeighbours(int p)
{
	List<Edge> output;
	for (int i = 0; i < this->getAmountPoints(); i++)
		if (m_matrix.getValue(p, i) != 0)
			output.pushBack(Edge(m_matrix.getValue(p, i), p, i, true));

	return output;
}


void MatrixGraph::print()
{
	m_matrix.print();
}

MatrixGraph * MatrixGraph::getBlanck()
{
	MatrixGraph* output = new MatrixGraph;

	int i = 0;
	while (output->getAmountPoints() != getAmountPoints())
		output->addPoint(Point(i++));

	return output;
}

int MatrixGraph::getEdgeValue(int a, int b)
{
	return m_matrix.getValue(a,b);
}

void MatrixGraph::setEdgeValue(int a, int b, int value)
{
	m_matrix.setValue(a, b, value);
}

void MatrixGraph::increaseEdgeValue(int a, int b, int value)
{
	m_matrix.setValue(a, b, m_matrix.getValue(a, b) + value);
}

void MatrixGraph::decreaseEdgeValue(int a, int b, int value)
{
	m_matrix.setValue(a, b, m_matrix.getValue(a, b) - value);
}

void MatrixGraph::resize(int newSize)
{
	m_matrix.resize(newSize);
	m_amountPoints = newSize;
}


MatrixGraph::~MatrixGraph()
{
	clear();
}
