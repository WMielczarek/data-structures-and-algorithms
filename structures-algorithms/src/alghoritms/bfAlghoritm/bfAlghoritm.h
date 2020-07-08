#pragma once

#include "alghoritms\IAlghoritm.h"

#include "structures\utilities\listGraph\listGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"
#include "structures\priorityQueue\PriorityQueue.h"



class bfAlghoritm :
	public IAlghoritm
{

public:

struct queueStructure {
	int point = 0;
	int parentPoint = -1;
	int value = std::numeric_limits<int>::max();

	queueStructure() = default;
	queueStructure(int point);
	queueStructure(int point, int parentPoint, int value);
	bool operator==(const queueStructure& e);
	bool operator<(const queueStructure& e);
	bool operator<=(const queueStructure& e);
	bool operator>(const queueStructure& e);
	bool operator>=(const queueStructure& e);
	bool operator!=(const queueStructure& e);
		
	friend std::ostream& operator<<(std::ostream& str, const queueStructure& s);

};

	bfAlghoritm() = default;
	~bfAlghoritm();
	void prepare(Graph* graph) override;
	void apply(Graph* graph) override;
	void setParameters(int newStartPoint, int = 0);
	void printResult();

private:
	

	int m_startPoint = 0;
	int m_currentGraphSize = 0;
	queueStructure* m_array = nullptr;
	List<Edge> m_primalEdgeList;
};

