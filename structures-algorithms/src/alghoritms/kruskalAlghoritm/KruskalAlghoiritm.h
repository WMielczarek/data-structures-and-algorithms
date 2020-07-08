#pragma once
#include "alghoritms\IAlghoritm.h"
#include "structures\priorityQueue\PriorityQueue.h"
#include "structures\list\List.h"

class KruskalAlghoiritm :
	public IAlghoritm
{
public:
	KruskalAlghoiritm() = default;
	~KruskalAlghoiritm() = default;

	void printResult();
	void apply(Graph* graph);
	void setParameters(int, int);
	void prepare(Graph* graph);
private:
	int m_currGraphSize = 0;
	PriorityQueue<Edge> m_queue;
	List<Edge> m_resultList;
};