#include "TspDynamic.h"
#include "TspData.h"
#include <vector>


TspDynamic::TspDynamic(TspData *data) {
	this->data = data;
}

float TspDynamic::solve() {
	std::vector<int> route(data->getSize());
	for (int i = 0; i < data->getSize(); i++) {
		route[i] = i;
	}
	return solve_rec(route, 0);
}

float TspDynamic::solve_rec(std::vector<int> &route, int start) {
	int best;
	int current;
	std::vector <int> temp(data->getSize());
	std::vector <int> minroute(data->getSize());

	//end
	if (start == data->getSize() - 2) {
		// return M[n-2][n-1] + M[n-1][0]
		return data->get(route[data->getSize() - 2], route[data->getSize() - 1]) + data->get(route[data->getSize() - 1], 0);
	}


	best = INT_MAX;
	for (int i = start + 1; i < data->getSize(); i++) {

		for (int j = 0; j < data->getSize(); j++) {
			temp[j] = route[j];
		}

		// Przesuniecie
		temp[start + 1] = route[i];
		temp[i] = route[start + 1];

		// if Znaleziono lepsza droge : rekurencja
		if (data->get(route[start], route[i]) + (current = solve_rec(temp, start + 1)) < best) {
			best = data->get(route[start], route[i]) + current;
			for (int k = 0; k < data->getSize(); k++) {
				minroute[k] = temp[k];
			}
		}
	}

	//Minimalna sciezka
	for (int i = 0; i < data->getSize(); i++) {
		route[i] = minroute[i];
	}

	return best;
}

TspDynamic::~TspDynamic() {
}

