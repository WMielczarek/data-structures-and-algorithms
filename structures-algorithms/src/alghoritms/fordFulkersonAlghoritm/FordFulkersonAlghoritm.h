#pragma once
#include "alghoritms\IAlghoritm.h"
#include "structures\utilities\edge\Edge.h"
#include "structures\list\List.h"

class FordFulkersonAlghoritm :
	public IAlghoritm
{
public:
	FordFulkersonAlghoritm() = default;
	~FordFulkersonAlghoritm() = default;
	
	void setMode(bool useDfs);
	void printResult();
	void apply(Graph* graph);
	void setParameters(int, int);
	void prepare(Graph* graph);
private:

	int m_startPoint = 0;
	int m_endPoint = 0;


	struct AngumentedPath {
		int flow = 0;
		List<Edge> edges;
		AngumentedPath() = default;
		AngumentedPath(int aFlow, List<Edge> aEdges) { flow = aFlow; edges = aEdges; };
	};

	bool searchDFS(Graph * graph, int* introducedArray, AngumentedPath &angumentedPath);
	bool searchBFS(Graph * graph, int* introducedArray, AngumentedPath &angumentedPath);
	void applyUsingBfs(Graph* graph);
	void applyUsingDfs(Graph* graph);
	List<AngumentedPath> m_angumentedPaths;
	bool m_useDfs = false;
};

