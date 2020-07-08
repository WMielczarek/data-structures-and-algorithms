#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
class flowController :
	public GenericProblemController
{
public:
	flowController();
	~flowController() = default;

	void handleAdditionalParameters(const std::string&) override;
	void parseEdgeString(const std::string&) override;
	void parseInput(const std::string & input) override;
	void init() override;
private:
	int m_startPoint = 0;
	int m_endPoint = 0;
};

