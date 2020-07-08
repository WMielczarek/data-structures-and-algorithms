#pragma once
#include "stdafx.h"

class Point
{
public:
	Point();
	Point(int name);
	~Point();

	int getName() const;

	static int getCounter();
	static void resetCounter(int base);

	bool operator==(const Point& p) const;

private:
	int m_name;
	static int Point::nameCounter;
};

