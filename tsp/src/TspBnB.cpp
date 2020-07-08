#include "TspBnB.h"
#include <iostream>
#include <algorithm>
#include <tuple>

TspBnB::TspBnB(TspData *data) {
	this->data = data;
	this->currentSize = data->getSize();
	this->startingSize = data->getSize();

	minCol = new int[currentSize]();
	minRow = new int[currentSize]();
	cols = new int[currentSize]();
	rows = new int[currentSize]();

	for(int i = 0; i < currentSize; i++) {
		cols[i] = i;
		rows[i] = i;
	}
}
std::tuple<int, int> TspBnB::getMaxElement(int *arr, int size) {
	int maxValue = 0;
	int maxValueIndex = -1;
	
	for(int i = 0; i < size; i++) {
		if( arr[i] > maxValue) {
			maxValue = arr[i];
			maxValueIndex = i;
		}
	}

	return std::make_tuple(maxValue, maxValueIndex);
}

void TspBnB::printRoute(int lowerBound) {
	for(auto it = route.begin(); it != route.end(); ++it) {
		std::cout << "(" << std::get<0>(*it)+1 << ", " << std::get<1>(*it)+1 << ") ";
	}

	std::cout << std::endl << lowerBound << std::endl;;
}

std::tuple<int, int> TspBnB::getLastCity() {
	int row = -1;
	int col = -1;
	for(int i = 0; i < startingSize; i++) {
		if(rows[i] != 0 && row == -1) {
			row = rows[i];
			rows[i] = 0;
		}
		if (cols[i] != 0 && col == -1) {
			col = cols[i];
			cols[i] = 0;
		}
	}

	return std::make_tuple(row, col);
}

int TspBnB::Bnb() {
	int lowerBound = 0;
	while (currentSize > 2) {

		//Obliczanie wartosci minimalnej w kazdym z wierszy macierzy kosztow.
		calcMin(ROW);
		for (int i = 0; i < currentSize; i++) {
			for (int j = 0; j < currentSize; j++) {
				//Redukowanie
				int val = data->get(i, j) - minRow[i];
				data->set(i, j, val);
			}
			lowerBound += minRow[i];
		}

		//Obliczanie wartosci minimalnej w kazdej z kolumn macierzy kosztow.
		calcMin(COLUMN);
		for (int i = 0; i < currentSize; i++) {
			for (int j = 0; j <currentSize; j++) {
				//Redukowanie
				int val = data->get(j, i) - minCol[i];
				data->set(j, i, val);

			}
			lowerBound += minCol[i];
		}
		calcMin(ROW, true);
		calcMin(COLUMN, true);

		//Wyliczanie najwiekszego z mimimow w kolumnie / wierszu.
		auto maxRow = getMaxElement(minRow, currentSize);
		auto maxCol = getMaxElement(minCol, currentSize);
		//data->print();

		int max = 0;
		int row = std::get<1>(maxRow);
		int rowMax = std::get<0>(maxRow);

		int col = std::get<1>(maxCol);
		int colMax = std::get<0>(maxCol);
	
		//Obliczanie kolumny / wiersza do usuniecia.

		int deleteRow = 0;
		int deleteCol = 0;

		bool maxIsInCol = false;
		//Jezeli wartosc maksymalna jest w wierszach to usuwamny dany wiersz i kolumne w ktorej dla danego wiersza wystepuje 0.
		if(colMax >= rowMax) {
			maxIsInCol = true;
			for (int i = 0; i < currentSize; i++) {
				if (data->get(i, col) == 0) {
					deleteRow = i;
					deleteCol = col;
					max = colMax;
				}
			}
		}//Jezli wartosc maksymalna jest w kolumnach to usuwamy dana kolumne i wiersz w ktorym dla danej kolumny wystepuje 0.
		else {
			for (int i = 0; i < currentSize; i++) {
				if (data->get(row, i) == 0) {
					deleteRow = row;
					deleteCol = i;
					max = rowMax;
				}
			}

		}

		//Blokowanie przejscia
		//data->print();
		data->set(deleteRow, deleteCol, INT_MAX);
		//data->print();
		
		//Zmniejszenie macierzy przez przesuniecie;

		//Przesuniecie kolumny
		for(int i = 0; i < currentSize; i++) {
			for(int j = deleteCol; j < currentSize-1; j++) {
				data->set(i, j, data->get(i, j + 1));
			}
		}

		//Przesuniecie wiersza
		for (int i = deleteRow; i < currentSize-1; i++) {
			for (int j = 0; j < currentSize; j++) {
				data->set(i, j, data->get(i + 1, j));
			}
		}

		//data->print();
		currentSize--;
		data->setSize(currentSize);
		//data->print();

		lowerBound += max;

		route.push_back(std::make_tuple(deleteRow, deleteCol));
		cols[deleteCol] = 0;
		rows[deleteRow] = 0;

	}
	//Dodanie pozosta³ych miast z macierzy 2x2
	route.pop_back();
	route.push_back(getLastCity());
	route.push_back(getLastCity());

	//Obliczanie wartosci minimalnej w kazdym z wierszy macierzy kosztow.
	calcMin(ROW);
	for (int i = 0; i < currentSize; i++) {
		for (int j = 0; j < currentSize; j++) {
			//Redukowanie
			int val = data->get(i, j) - minRow[i];
			data->set(i, j, val);
		}
		lowerBound += minRow[i];
	}

	//Obliczanie wartosci minimalnej w kazdej z kolumn macierzy kosztow.
	calcMin(COLUMN);
	for (int i = 0; i < currentSize; i++) {
		for (int j = 0; j <currentSize; j++) {
			//Redukowanie
			int val = data->get(j, i) - minCol[i];
			data->set(j, i, val);

		}
		lowerBound += minCol[i];
	}

	//printRoute(lowerBound);;
	return lowerBound;
}

void TspBnB::print() const {
	for (int i = 0; i < currentSize; i++) {
		for (int j = 0; j < currentSize; j++) {
			std::cout << data->get(i, j) << " ";
		}
		std::cout << "\n";
	}
}

void TspBnB::calcMin(bool column, bool doubleZero) {
	for (int i = 0; i < currentSize; i++) {
		int min = INT_MAX;
		int zeroCounter = 0;

		for (int j = 0; j < currentSize; j++) {
			int newValue = column ? data->get(j, i) : data->get(i, j);

			if (newValue < min) {

				if(newValue == 0 && doubleZero) {
					zeroCounter++;

					if(zeroCounter == 2) {
						min = 0;
					}
				} else {
					min = newValue;
				}
			}
		}
		if(column) {
			minCol[i] = min;
		} else {
			minRow[i] = min;
		}
	}
}


TspBnB::~TspBnB() {
	delete[]minCol;
	delete[]minRow;

	delete[] cols;
	delete[] rows;
}