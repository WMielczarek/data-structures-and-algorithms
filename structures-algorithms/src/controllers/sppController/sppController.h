#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
class sppController :
	public GenericProblemController
{
public:
	sppController();
	~sppController() = default;

	void init() override;
	void parseInput(const std::string &input) override;
	void parseEdgeString(const std::string &edgeString) override;
	void handleAdditionalParameters(const std::string &edgeString);
	

private:
	int edgeCount = 0;
	int pointCount = 0;
};

