#pragma once
#include "source\controllers\genericController\GenericController.h"
#include "structures\utilities\ListGraph\ListGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"
#include "alghoritms\IAlghoritm.h"

class GenericProblemController :
	public GenericController
{
protected:
	MatrixGraph m_matrix;
	ListGraph m_list;
	std::unique_ptr<IAlghoritm> m_alghoritm;

	int startPoint = 0;
	int amountOfPoints = 0;
	int amountOfEdges = 0;

public:
	GenericProblemController() = default;
	virtual ~GenericProblemController() = default;

	virtual void loadFromFile();
	virtual void handleAdditionalParameters(const std::string&) = 0;
	virtual void parseEdgeString(const std::string&);
	virtual void print();
	void generateGraph(int density, int vertex, int range, int baseValue, bool directed);
};

