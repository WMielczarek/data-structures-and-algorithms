#pragma once
#include "views\genericView\GenericView.h"
class sppMenu :
	public GenericView
{
public:
	sppMenu() = default;
	~sppMenu() = default;
	void print() override;
};

