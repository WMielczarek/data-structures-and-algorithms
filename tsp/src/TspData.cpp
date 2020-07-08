#include "TspData.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <fstream>

int TspData::randomIntFromRange(int min, int max) {
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(min, max);

	return distr(generator);
}

int TspData::getSize() {
	return size;
}

int TspData::get(int i, int j) {
	return data[i][j];
}

void TspData::set(int i, int j, int value) {
	data[i][j] = value;
}

void TspData::generateData(int min, int max, int size) {
	this->size = size;

	data = new int*[size]();
	resetData = new int*[size]();
	for (int i = 0; i < size; i++) {
		data[i] = new int[size]();
		resetData[i] = new int[size]();
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int rand = randomIntFromRange(min, max);

			if (i == j) {
				rand = INT_MAX;
			}

			if (data[i][j] == 0) {
				data[i][j] = rand;
				resetData[i][j] = rand;
			}
			if (data[j][i] == 0) {
				data[j][i] = rand;
				resetData[j][i] = rand;
			}
		}
	}
}

bool TspData::load(std::string filename) {
	std::ifstream file;
	file.open("data\\"+filename);

	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku data\\'"<<filename<<"'\n";
		size = -1;
		return false;
	}

	file >> size;

	data = new int*[size]();
	resetData = new int*[size]();

	for (int i = 0; i < size; i++) {
		data[i] = new int[size]();
		resetData[i] = new int[size]();

	}


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			file >> data[i][j];
			resetData[i][j] = data[i][j];
		}
	}

	file.close();

	return true;
}

void TspData::save(std::string filename) {
	std::ofstream file;
	file.open("data\\"+filename);

	file << size << "\n";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			file << data[i][j] << " ";
		}
		file << "\n";
	}
}

void TspData::print() {
	if (size == -1) {
		return;
	}
	std::cout << std::setw(3);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << std::setw(3);
			if (data[i][j] >= 2000000) {
				std::cout << "-";
			}
			else {
				std::cout << data[i][j];

			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void TspData::reset() {
	size = resetSize;
	for(int i = 0; i < resetSize; i++) {
		for(int j = 0; j < resetSize; j++) {
			data[i][j] = resetData[i][j];
		}
	}
}

void TspData::setSize(int size) {
	this->size = size;
}

TspData::~TspData() {
	for (int i = 0; i < size; i++) {
		delete[] data[i];
		delete[] resetData[i];
	}
	delete[] data;
	delete[] resetData;
}
