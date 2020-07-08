#pragma once
#include "TspData.h"
#include <vector>

class TspDynamic {
private:
	TspData *data;
	float calcRoute(std::vector<int> route);
public:
	TspDynamic(TspData *data);
	float solve();
	float solve_rec(std::vector<int> &route, int start);
	~TspDynamic();
};

