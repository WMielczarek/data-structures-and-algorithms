#pragma once
#include "controllers\testControllers\genericTestController\genericTestController.h"
#include "structures\utilities\ListGraph\ListGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"

class Tester :
	public genericTestController
{
public:
	Tester() = default;
	~Tester() = default;

	void runAllTests() override;

private:

	static const int densityArraySize = 4;
	static const int vertexArraySize = 5;

	int densityTable[densityArraySize] = { 25, 50, 75, 99 };
	int vertexCountTable[vertexArraySize] = { 100, 200, 300, 400, 500};
	int valueRange = 100;
	int valueBase = 1;



	void sppTests();
	void djikstraTest();
	void bfTest();
	void mstTests();
	void kruskalTest();
	void primTest();
	void flowTests();
	void ffDFSTest();
	void ffBFSTest();
};

