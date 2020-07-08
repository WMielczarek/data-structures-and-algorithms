#pragma once

#include "structures\utilities\graph\Graph.h"

enum class AlghoritmOutputSetting {
	list,
	matrix
};

class IAlghoritm {
protected:
	AlghoritmOutputSetting outputSetting;

public:
	IAlghoritm() : outputSetting(AlghoritmOutputSetting::list) {};
	void setOuputType(AlghoritmOutputSetting outputType) { outputSetting = outputType; };
	virtual void printResult() = 0;
	virtual void apply(Graph* graph) = 0;
	virtual void setParameters(int, int) = 0;
	virtual void prepare(Graph* graph) = 0;
};

