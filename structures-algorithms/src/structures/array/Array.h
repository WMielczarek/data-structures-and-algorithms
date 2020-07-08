#pragma once
#include "stdafx.h"

template <class T>
class Array
{
public:
	Array() :
		isCheap(true)
		, allocatedSize(0)
		, currSize(0)
		, data(nullptr)
	{};

	Array(int size)
	{
		data = new T[size];
		allocatedSize = size;
		isCheap = false;
		currSize = 0;
	};

	Array(const Array<T> &a)
	{
		for (int i = 0; i < a.getSize(); i++)
			pushBack(a[i]);
	}

	~Array() { clearStructure(); };


	void printData() const {
		if (!isEmpty())
			for (int index = 0; index < this->currSize; index++)
			{
				std::cout << getValue(index);
				if (isDisplayedInline())
					std::cout << ' ';
				else
					std::cout << std::endl;
			}
		else
			std::cout << "Tablica jest pusta!";
	};


	void addElement(const int index, const T &value) {
		if (isEmpty() && index == 0)
		{
			data = new T[1];
			allocatedSize = 1;
			data[index] = T(value);
			++currSize;
		}
		else if (index >= 0 && index <= currSize)
		{
			if (allocatedSize < currSize + 1)
				if (isCheap)
					this->realocate(allocatedSize + 1);
				else
					realocateByStep();
			moveElementsRight(index);
			data[index] = T(value);
			++currSize;
		}
		else
		{
			throw std::invalid_argument("Indeks poza zasiêgiem tablicy");
		}
	};


	void pushBack(const T &value) {
		addElement(getSize(), value);
	};


	void removeElement(const int index) {
		if (index >= 0 && index < getSize())
		{
			moveElementsLeft(index);
			if (isCheap)
				realocate(allocatedSize - 1);
			else
				currSize--;
		}
		else
		{
			std::stringstream ss;
			ss << "Indeks poza zasiêgiem tablicy( podano: " << index << " max: " << getSize();
			throw std::invalid_argument(ss.str());
		}
	};


	void clearStructure() {
		if (!(data == nullptr))
		{
			delete[] data;
			currSize = 0;
			allocatedSize = 0;
		}
	};


	void realocate(const int newSize) {
		if (newSize == 0)
		{
			clearStructure();
			return;
		}

		T* newData = new T[newSize];
		int moveDataToIndex = (newSize > currSize) ? currSize : newSize;
		for (int index = 0; index < moveDataToIndex; index++)
			newData[index] = T(data[index]);
		clearStructure();
		data = newData;
		allocatedSize = newSize;
		currSize = moveDataToIndex;
	};


	bool findValue(T toFind) {
		for (int index = 0; index < currSize; index++)
			if (data[index] == toFind)
				return true;
		return false;
	};

	int getSize() const
	{
		return currSize;
	};

	bool isEmpty() const
	{
		return (currSize == 0);
	};

	T getValue(int index) const
	{
		if (index >= currSize)
			throw std::invalid_argument("Out of Array range");
		return data[index];
	};

	void setValue(int index, const T &value) {
		if (index >= currSize)
			throw std::invalid_argument("Out of Array range");
		data[index] = value;
	};
	void swap(int b, int a) {
		T tmp = data[b];
		data[b] = data[a];
		data[a] = tmp;
	};

	T operator[](int index) const {
		return getValue(index);
	};

	T* getPtr(int index) const
	{
		return &(data[index]);
	};

	int getAllocatedSize() const
	{
		return allocatedSize;
	};


	void setInlineDisplay(bool toSet)
	{
		inlineDisplay = toSet;
	};

	bool isDisplayedInline() const
	{
		return inlineDisplay;
	}

private:
	T* data = nullptr;
	int currSize = 0;
	int allocatedSize = 0;
	int realocationStep = 1;

	void moveElementsRight(int index) {
		for (int i = currSize - 1; i > index; --i)
			data[i] = data[i - 1];
	};
	void moveElementsLeft(int index) {
		for (int i = index; i < currSize - 1; ++i)
			data[i] = data[i + 1];
	};

	bool isCheap;
	bool inlineDisplay = true;
protected:
	void realocateByStep() {
		realocate(allocatedSize * 2);
	};
};

template<class T>
std::ostream& operator<<(std::ostream& str, const Array<T>& s)
{
	for (int i = 0; i < s.getSize(); i++)
	{
		str << s.getValue(i);
		if (s.isDisplayedInline())
			str << ' ';
		else
			str << std::endl;
	}
	return str;
}