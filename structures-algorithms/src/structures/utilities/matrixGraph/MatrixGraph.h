#pragma once
#include "structures\utilities\graph\Graph.h"
#include "structures\matrix\Matrix.h"
#include "structures\utilities\point\Point.h"

class MatrixGraph :
	public Graph
{
public:
	MatrixGraph();
	MatrixGraph::MatrixGraph(MatrixGraph& m);

	void clear();
	void addEdge(const Edge &e) override;
	void addPoint(const Point &p) override;
	shared_ptr<Edge> getEdge(int a, int b) override;
	List<Edge> getEdges() override;
	List<Edge> getNeighbours(int p) override;
	void print();
	MatrixGraph* getBlanck() override;
	int getEdgeValue(int a, int b) override;
	void setEdgeValue(int a, int b, int value) override;
	void increaseEdgeValue(int a, int b, int value) override;
	void decreaseEdgeValue(int a, int b, int value) override;

	void resize(int newSize) override;

	virtual ~MatrixGraph();

private:
	Matrix m_matrix;
};

