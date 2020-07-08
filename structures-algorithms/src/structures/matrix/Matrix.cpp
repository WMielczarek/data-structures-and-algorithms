#include "stdafx.h"
#include "Matrix.h"


using namespace std;


Matrix::Matrix()
{
	m_data = nullptr;
}

Matrix::~Matrix()
{
	clearData();
}

void Matrix::resize(int newSize)
{
	if (newSize == 0)
	{
		clearData();
		return;
	}

	int** newData = new int*[newSize];
	for (int i = 0; i < newSize; i++)
	{
		newData[i] = new int[newSize];
		for (int j = 0; j < newSize; j++)
			newData[i][j] = 0;
	}

	int copyMaxIndex = (newSize > getSize()) ? getSize() : newSize;

	for (int x = 0; x < copyMaxIndex; x++)
		for (int y = 0; y < copyMaxIndex; y++)
			newData[x][y] = getValue(x, y);

	clearData();
	m_data = newData;
	m_size = newSize;
}

void Matrix::print()
{
	cout << "\t ";
	for (int x = 0; x < getSize(); x++)
	{
		cout.width(4);
		cout << x << " ";
	}
	cout << endl;

	cout << "\t";
	for (int x = 0; x < getSize()*4; x++)
		cout << "--";
	cout << endl;

	for (int x = 0; x < getSize(); x++)
	{
		cout << x << "\t" << "|";
		for (int y = 0; y < getSize(); y++)
		{
			cout.width(4);
			cout << getValue(x, y) << ' ';
		}
		cout << endl;
	}
}

void Matrix::setValue(int x, int y, int value)
{
	m_data[x][y] = value;
}

int Matrix::getValue(int x, int y)
{
	return m_data[x][y];
}

int Matrix::getSize()
{
	return m_size;
}

void Matrix::clearData()
{
	if (m_data != nullptr)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_data[i] != nullptr) 
			{
				delete[] m_data[i];
				m_data[i] = nullptr;
			}
		}
		delete[] m_data;
		m_data = nullptr;
	}
	m_size = 0;
}
