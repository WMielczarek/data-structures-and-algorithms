#pragma once

#include "structures\utilities\point\Point.h"

class Edge
{
	friend std::ostream& operator<<(std::ostream& str, const Edge& s);

public:
	~Edge();
	Edge::Edge() = default;
	Edge::Edge(int value, Point a, Point b);
	Edge::Edge(int value, Point a, Point b, bool isDirected);
	Edge::Edge(const Edge &e);
	
	int getValue() const;
	Point getStart() const;
	int getStartName() const;
	Point getEnd() const;
	int getEndName() const;
	
	void setStart(const Point &a);
	void setEnd(const Point &b);
	void setValue(const int &value);

	bool operator==(const Edge& e) const;
	bool operator<(const Edge& e);
	bool operator<=(const Edge& e);
	bool operator>(const Edge& e);
	bool operator>=(const Edge& e);
	bool operator!=(const Edge& e);

	Edge& Edge::operator=(Edge& e);

	void setDirected(bool toSet);
	bool isDirected()const;

	Edge getInverted() const;
	
private:
	bool m_directed = false;
	int m_value = 0;
	Point m_startPoint;
	Point m_endPoint;
};
