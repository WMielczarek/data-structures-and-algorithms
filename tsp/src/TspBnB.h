#pragma once
#include "TspData.h"
#include <tuple>
#include <vector>

class TspBnB {
	static const bool COLUMN = true;
	static const bool ROW = false;

	TspData *data;
	int* minCol;
	int* minRow;
	int currentSize;
	int startingSize;
	int* cols;
	int* rows;
	std::vector<std::tuple<int, int> > route;
	void calcMin(bool column, bool doubleZero = false);
	std::tuple<int, int> getMaxElement(int *arr, int size);
	void printRoute(int lwoerBOund);
	std::tuple<int, int> getLastCity();

public:
	TspBnB(TspData *data);
	int Bnb();
	void print() const;
	~TspBnB();
};
