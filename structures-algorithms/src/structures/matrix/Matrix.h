#pragma once
class Matrix
{
public:
	Matrix();
	virtual ~Matrix();

	void resize(int newSize);
	void print();

	void setValue(int x, int y, int value);
	int getValue(int x, int y);

	int getSize();

	void clearData();

private:
	int m_size = 0;
	int ** m_data;
};

