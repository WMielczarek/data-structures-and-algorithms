#pragma once
#include "stdafx.h"

#include "structures/array/Array.h"
#include "structures\utilities\edge\Edge.h"

template<class T>
class PriorityQueue
{
public:
	PriorityQueue();
	PriorityQueue(int size);
	virtual ~PriorityQueue() {};

	virtual void addElement(T &value);
	virtual void clearStructure();
	virtual bool findValue(T &value);
	virtual T popElement();
	virtual T popElement(const int index);
	virtual int getSize();
	virtual void printData();
	int getIndex(const T&value);

private:
	virtual void fixUp();
	virtual void fixDown(int index);
	
protected:
	std::unique_ptr<Array<T>> array;
	void printNode(std::string &sMiddle, std::string &sBefore, int currNode);
	
};

template<class T>
PriorityQueue<T>::PriorityQueue()
{
	array = make_unique<Array<T>>(20);
};


using namespace std;

template<class T>
PriorityQueue<T>::PriorityQueue(int size)
{
	array = make_unique<Array<T>>(size * 2);
};

template<class T>
void PriorityQueue<T>::addElement(T &elem)
{
	array->pushBack(elem);
	fixUp();
};

template<class T>
void PriorityQueue<T>::clearStructure()
{
	array->clearStructure();
};

template<class T>
bool PriorityQueue<T>::findValue(T &value)
{
	if (array->isEmpty())
		return false;

	return array->findValue(value);
};

template<class T>
T PriorityQueue<T>::popElement()
{
	if (array->getSize() != 0)
	{
		T output = array->getValue(0);
		array->swap(0, array->getSize() - 1);
		array->removeElement(array->getSize() - 1);
		fixDown(0);
		return output;
	}
	else
		throw new logic_error("Queue is empty!");
}
template<class T>
T PriorityQueue<T>::popElement(const int index)
{
	if (array->getSize() != 0)
	{
		T output = array->getValue(index);
		array->swap(index, array->getSize() - 1);
		array->removeElement(array->getSize() - 1);
		if(index < array->getSize())
			fixDown(index);
		return output;
	}
	else
		throw new logic_error("Queue is empty!");
};

template<class T>
int PriorityQueue<T>::getSize()
{
	return array->getSize();
};

template<class T>
void PriorityQueue<T>::printData()
{
	printNode(string(""), string(""), 0);
}
template<class T>
int PriorityQueue<T>::getIndex(const T & value)
{
	for (int i = 0; i < getSize(); i++)
		if (array->getValue(i) == value)
			return i;
	return -1;
};

template<class T>
void PriorityQueue<T>::fixUp()
{
	if (array->getSize() < 1)
		return;
	int currNode = array->getSize() - 1;
	int parentNode = (currNode - 1) / 2;
	
	while (currNode != 0)
	{
		if (array->getValue(parentNode) > array->getValue(currNode))
			array->swap(parentNode, currNode);
		currNode = parentNode;
		parentNode = parentNode = (currNode - 1) / 2;
	}
};

template<class T>
void PriorityQueue<T>::fixDown(int index)
{
	int leftChild;
	int rightChild;
	int parent;
	bool isLeft, isRight, shifted;
	isLeft = isRight = shifted = true;

	while ((isLeft || isRight) && shifted)
	{
		isLeft = isRight = true;
		shifted = false;
		leftChild = index * 2 + 1;
		rightChild = index * 2 + 2;

		isLeft = (leftChild < array->getSize());
		isRight = (rightChild < array->getSize());
		parent = (int)(index - 1) / 2;

		if (parent >= 0 && parent != index)
			if (array->getValue(parent) > array->getValue(index))
			{
				fixDown(parent);
				return;
			}

		if (isRight && isLeft)
		{
			if (array->getValue(rightChild) < array->getValue(leftChild))
			{
				if (array->getValue(rightChild) < array->getValue(index))
				{
					array->swap(index, rightChild);
					index = rightChild;
					shifted = true;
				}
			}
			else
			{
				if (array->getValue(leftChild) < array->getValue(index))
				{
					array->swap(index, leftChild);
					index = leftChild;
					shifted = true;
				}
			}
		}
		else if (isRight)
		{
			if (array->getValue(rightChild) < array->getValue(index))
			{
				array->swap(index, rightChild);
				index = rightChild;
				shifted = true;
			}
		}
		else if (isLeft)
		{
			if (array->getValue(leftChild) < array->getValue(index))
			{
				array->swap(index, leftChild);
				index = leftChild;
				shifted = true;
			}
		}
	}
};

template<class T>
void PriorityQueue<T>::printNode(string& sMiddle, string &sBefore, int currNode)
{
	string s;
	if (currNode < array->getSize())
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)126), 2 * currNode + 2);

		s = s.substr(0, sMiddle.length() - 2);

		cout << s << sBefore << array->getValue(currNode) << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)126), 2 * currNode + 1);
	}
};
