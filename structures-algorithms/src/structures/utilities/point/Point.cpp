#include "stdafx.h"
#include "Point.h"


int Point::nameCounter = 0;

Point::Point()
{
	//m_name = getCounter();
}

Point::Point(int name)
	: m_name(name)
{
//	resetCounter(name + 1);
}

Point::~Point()
{
	//resetCounter(getCounter() - 1);
}

int Point::getName() const
{
	return m_name;
}

int Point::getCounter()
{
	return Point::nameCounter++;
}

void Point::resetCounter(int base)
{
	Point::nameCounter = base;
}

bool Point::operator==(const Point & p) const
{
	return getName() == p.getName();
}
