#pragma once
#include "../genericView/GenericView.h"
class appMenu :
	public GenericView
{
public:
	virtual ~appMenu() = default;
	virtual void print();
};

