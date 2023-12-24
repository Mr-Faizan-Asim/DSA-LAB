#pragma once
#include<vector>
#include<iostream>
#include<list>
using namespace std;
// hashing using Chaining
class ChainingHash
{
private:
	int size;
	vector<list<int>> table;
public:
	ChainingHash(int tableSize) : size(tableSize), table(tableSize) {}
	int hash(int val)
	{
		return val % size;
	}
	void insert(int val)
	{
		int index = hash(val);
		table[index].push_back(val);
	}
	bool Search(int val)
	{
		int index = hash(val);
		for (auto i : table[index])
		{
			if (i == val)
			{
				return true;
			}
		}
		return false;
	}
	void Delete(int val)
	{
		int index = hash(val);
		table[index].remove(val);
	}

	void printTable() const {
		for (int i = 0; i < size; ++i) {
			cout << "Index " << i << ": ";
			for (int value : table[i]) {
				std::cout << value << " ";
			}
			cout << "\n";
		}
	}

};
// Quadratic 
class QuadraticProbingTable {
private:
	int tableSize;
	vector<int> table;
public:
	QuadraticProbingTable(int size) : tableSize(size), table(size, -1) {}
	int HashValue(int val)
	{
		return val % tableSize;
	}
	void insert(int val)
	{
		int i = 0;
		while (table[(HashValue(val) + i*i) % tableSize] != -1)
		{
			i++;
		}
		table[(HashValue(val) + i * i) % tableSize] = val;
	}
	bool Search(int val)
	{
		int i = 0;
		while (table[(HashValue(val) + i * i) % tableSize] != -1)
		{
			if (table[(HashValue(val) + i * i) % tableSize] == val)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	void Delete(int val)
	{
		int i = 0;
		while (table[(HashValue(val) + i * i) % tableSize] != -1)
		{
			if (table[(HashValue(val) + i * i) % tableSize] == val)
			{
				table[(HashValue(val) + i * i) % tableSize] = 0;
			}
			i++;
		}
	}
	void Print()
	{
		for (auto i : table)
		{
			cout << i << endl;
		}
	}

};


// Linear Probing Table
class LinearProbingTable {
private:
	int tableSize;
	vector<int> table;
public: 
	LinearProbingTable(int size) : tableSize(size),table(size,-1){}
	int HashValue(int val)
	{
		return val % tableSize;
	}
	void insert(int val)
	{
		int i = 0;
		while (table[(HashValue(val) + i) % tableSize] != -1)
		{
			i++;
		}
		table[(HashValue(val) + i) % tableSize] = val;
	}
	bool Search(int val)
	{
		int i = 0;
		while (table[(HashValue(val) + i) % tableSize] != -1)
		{
			if (table[(HashValue(val) + i) % tableSize] == val)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	void Delete(int val)
	{
		int i = 0; 
		while (table[(HashValue(val) + i) % tableSize] != -1)
		{
			if (table[(HashValue(val) + i) % tableSize] == val)
			{
				table[(HashValue(val) + i) % tableSize] = 0;
			}
			i++;
		}
	}
	void Print()
	{
		for (auto i : table)
		{
			cout << i << endl;
		}
	}
	
};

