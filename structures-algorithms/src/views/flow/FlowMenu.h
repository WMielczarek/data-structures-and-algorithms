#pragma once
#include "views\genericView\GenericView.h"
class FlowMenu :
	public GenericView
{
public:
	virtual ~FlowMenu() = default;
	void print() override;
};

