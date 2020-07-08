#include "Tsp.h"
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>

Tsp::Tsp(TspData *data) {
	this->data = data;
}

int Tsp::calcRoute(std::vector<int> route) {
	int currentRoute = 0;

	int firstCity = -1;
	for (auto it = route.begin(); it != route.end(); it++) {
		if (firstCity == -1) {
			firstCity = *it;
			continue;
		}
		currentRoute += data->get(firstCity, *it);
		firstCity = *it;
	}
	currentRoute += data->get(route.back(), route.front());
	return currentRoute;
}

void Tsp::printRoute(std::vector<int> route) {
	for (auto it = route.begin(); it != route.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int Tsp::bruteForce() {
	int minPathDist = INT_MAX;
	int newPathDist = 0;
	std::vector<int> minPath;
	std::vector<int> newPath;
	
	for (int i = 0; i < data->getSize(); i++) {
		minPath.push_back(i);
	}
	std::sort(minPath.begin(), minPath.end());
	newPath = minPath;
	do {
		newPathDist = calcRoute(newPath);

		if (newPathDist < minPathDist) {
			minPathDist = newPathDist;
			minPath = newPath;
		}

	} while ( std::next_permutation(newPath.begin(), newPath.end()) );

	//std::cout << "Minimalna droga: " << minPathDist << std::endl;
	//std::cout << "Droga: ";

	//printRoute(minPath);
	return minPathDist;
}