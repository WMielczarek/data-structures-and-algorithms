#pragma once
#include <string>


class TspData {
	int size;
	int **data;
	int **resetData;
	int resetSize;
	int randomIntFromRange(int min, int max);
public:
	void generateData(int min, int max, int size);
	void print();
	bool load(std::string filename);
	void save(std::string filename);

	void reset();
	int getSize();
	void setSize(int size);
	int get(int i, int j);
	void set(int i, int j, int value);

	~TspData();
};
