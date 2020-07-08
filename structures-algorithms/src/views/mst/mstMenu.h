#pragma once
#include "views\genericView\GenericView.h"
class mstMenu :
	public GenericView
{
public:
	mstMenu() = default;
	~mstMenu() = default;
	void print() override;
};

