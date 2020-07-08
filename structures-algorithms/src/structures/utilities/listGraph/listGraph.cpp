#include "stdafx.h"
#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph()
{

}

ListGraph::ListGraph(ListGraph& l)
{
	resize(l.getAmountPoints());

	for (int i = 0; i < getAmountPoints(); i++)
	{
		List<Edge> neighbours = l.getNeighbours(i);
		while (neighbours.getSize() != 0)
			addEdge(neighbours.popFrontElement());
	}
}

void ListGraph::clear()
{
	for (int i = 0; i < getSize(); i++)
		m_data[i].clearList();
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
	m_amountEdges = 0;
	m_amountPoints = 0;
}

void ListGraph::addEdge(const Edge &e)
{
	Node* lastNode = &(m_data[e.getStart().getName()]);

	while (lastNode->next != nullptr)
		lastNode = lastNode->next;
	
	lastNode->next = new Node();
	lastNode->next->data = new Edge(e);
	lastNode->next->prev = lastNode;
	if (!e.isDirected())
	{
		Edge newE = e.getInverted();
		newE.setDirected(true);
		addEdge(newE);
		isDirected = false;
	}
	m_amountEdges++;
}

void ListGraph::addPoint(const Point &p)
{
	if (m_data == nullptr)
	{
		m_data = new Node[1];
	}
	else
	{
		int newSize = getSize() + 1;
		Node* newData = new Node[newSize];
		for (int i = 0; i < getSize(); i++)
		{
			newData[i] = m_data[i];
			Node* tmp = m_data[i].next;
			while (tmp != nullptr)
			{
				newData[i].next = tmp;
				tmp = tmp->next;
			}
		}

		delete[] m_data;
		m_data = newData;

	}
	m_size++;
	m_data[getSize() - 1].data = new Edge;
	m_data[getSize() - 1].data->setStart(p);
	m_amountPoints++;
}

shared_ptr<Edge> ListGraph::getEdge(int a, int b)
{
	if (a >= m_size || a < 0)
		throw new out_of_range("Podany punkt jest poza zasiêgiem tablicy");
	
	Node* curr = m_data[a].next;
	
	while (curr != nullptr)
	{
		if (curr->data->getEnd().getName() == b)
			return make_shared<Edge>(*(curr->data));
		else
			curr = curr->next;
	}
	return nullptr;
}

List<Edge> ListGraph::getEdges()
{
	List<Edge> output;


	for (int i = 0; i < getAmountPoints(); i++)
	{
		auto neighbourList = getNeighbours(i);
		while (neighbourList.getSize() != 0)
			output.addElement(neighbourList.popFrontElement());
	}


	return output;
}

List<Edge> ListGraph::getNeighbours(int p)
{
	List<Edge> output;
	Node* curr = (m_data[p]).next;

	while (curr != nullptr)
	{
		output.pushBack(*(curr->data));
		curr = curr->next;
	}
	return output;
}

int ListGraph::getSize()
{
	return m_size;
}

void ListGraph::print()
{
	for (int i = 0; i < getSize(); i++)
	{
		auto currNode = &(m_data[i]);
		while (currNode != nullptr)
		{
			if (currNode == &(m_data[i]))
			{
				cout << currNode->data->getStart().getName() << " ";
				cout << " | ";
			}
			else
				cout << currNode->data->getEnd().getName() << " [" << currNode->data->getValue() << "] ";
			currNode = currNode->next;
		}
		cout << endl;
	}
}

int ListGraph::getEdgeValue(int a, int b)
{
	auto edge = getEdge(a, b);
	if (edge == nullptr)
		return 0;
	else
		return edge->getValue();
}

void ListGraph::setEdgeValue(int a, int b, int value)
{
	if (a >= m_size || a < 0)
		throw new out_of_range("Podany punkt jest poza zasiêgiem tablicy");

	if (value == 0)
		removeEdge(a, b);

	auto edge = m_data[a].next;

	while (edge != nullptr)
	{
		if (edge->data->getEndName() == b)
			break;
		else
			edge = edge->next;
	}
	
	if (edge == nullptr)
		addEdge(Edge(value, a, b, true));
	else
		edge->data->setValue(value);
		
}

void ListGraph::increaseEdgeValue(int a, int b, int value)
{
	if (a >= m_size || a < 0)
		throw new out_of_range("Podany punkt jest poza zasiêgiem tablicy");

	auto edge = m_data[a].next;

	while (edge != nullptr)
	{
		if (edge->data->getEndName() == b)
			break;
		else
			edge = edge->next;
	}

	if (edge == nullptr)
		addEdge(Edge(value, a, b, true));
	else
		edge->data->setValue(edge->data->getValue() + value);
}

void ListGraph::decreaseEdgeValue(int a, int b, int value)
{
	if (a >= m_size || a < 0)
		throw new out_of_range("Podany punkt jest poza zasiêgiem tablicy");

	auto edge = m_data[a].next;

	while (edge != nullptr)
	{
		if (edge->data->getEndName() == b)
			break;
		else
			edge = edge->next;
	}

	if (edge == nullptr)
		addEdge(Edge(-1*value, a, b, true));
	else
	{
		if (edge->data->getValue() - value == 0)
			this->removeEdge(a, b);
		else
			edge->data->setValue(edge->data->getValue() - value);
	}
}

void ListGraph::removeEdge(int a, int b)
{
	Node* toDelete = m_data[a].next;

	while (toDelete != nullptr)
	{
		if (toDelete->data->getEndName() == b)
			break;
		else
			toDelete = toDelete->next;
	}

	if (toDelete->next != nullptr)
	{
		toDelete->next->prev = toDelete->prev;
		toDelete->prev->next = toDelete->next;
		toDelete->next = nullptr;
	}
		
	
	toDelete->prev->next = nullptr;
	toDelete->clearList();
}

ListGraph * ListGraph::getBlanck()
{
	ListGraph* output = new ListGraph();
	int i = 0;
	while (output->getSize() != getSize())
		output->addPoint(Point(i++));

	return output;
}

void ListGraph::resize(int newSize)
{
	for (int i = getSize(); i < newSize; i++)
		addPoint(i);
}

ListGraph::~ListGraph()
{
	clear();
}