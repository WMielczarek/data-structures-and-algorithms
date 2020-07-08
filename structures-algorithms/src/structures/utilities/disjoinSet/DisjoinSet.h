#pragma once
class DisjoinSet
{
public:
	DisjoinSet(const int &maxSize);
	~DisjoinSet();

	void makeSet(int toCreate);
	void makeUnion(int setA, int setB);
	int findSet(int toFind) const;
	int getSetRank(int set) const;
	bool checkIntegration() const;
	int getSetSize()const;

	void print() const;

private:
	int setSize = 0;
	struct Node{
		int rank = 0;
		int id;
		Node* parent = nullptr;
		Node(int aId) : id(aId) {};
		Node() = default;
	};

	Node* m_array = nullptr;
};

