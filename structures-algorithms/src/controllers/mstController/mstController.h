#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
class mstController :
	public GenericProblemController
{
public:
	mstController();
	~mstController() = default;

	void handleAdditionalParameters(const std::string&) override;
	void parseEdgeString(const std::string&) override;
	void parseInput(const std::string & input) override;
	void init() override;

};

