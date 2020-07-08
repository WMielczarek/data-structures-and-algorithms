#pragma once
#include "alghoritms\IAlghoritm.h"
#include "structures\utilities\listGraph\listGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"
#include "structures\priorityQueue\PriorityQueue.h"
#include "structures\array\Array.h"


struct pointValueStructure
{
public:
	pointValueStructure() = default;
	pointValueStructure(int aPoint) { point = aPoint; };
	pointValueStructure(int aPoint, int aValue) { point = aPoint; value = aValue; };
	int point = 0;
	int value = std::numeric_limits<int>::max();

	bool operator==(const pointValueStructure& e);
	bool operator<(const pointValueStructure& e);
	bool operator<=(const pointValueStructure& e);
	bool operator>(const pointValueStructure& e);
	bool operator>=(const pointValueStructure& e);
	bool operator!=(const pointValueStructure& e);
	friend std::ostream& operator<<(std::ostream& str, const pointValueStructure& s);
};

/**
	add O(logn)
	extract-min O(1)
	contains O(logn)
	decrease(logn)

	So, Djikstra O(nlogn)
*/
class DjikstraAlghoritm :
	public IAlghoritm
{
private:
	int startPoint = 0;
	int currentGraphSize = 0;
	std::shared_ptr<PriorityQueue<pointValueStructure>> queue;
	int* m_pathArray = nullptr;
	int* m_distanceArray = nullptr;
public:
	DjikstraAlghoritm();
	~DjikstraAlghoritm();

	void prepare(Graph* graph) override;
	void apply(Graph* graph) override;
	void setParameters(int newStartPoint, int = 0);
	void printResult();
};


