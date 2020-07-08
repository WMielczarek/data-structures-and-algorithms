#pragma once

#include <vector>
#include "TspData.h"

using namespace std;
class Tsp {
	TspData *data;
    void printRoute(std::vector<int> route);
    int calcRoute(std::vector<int> route);
public:
	Tsp(TspData *data);
	int bruteForce();
};