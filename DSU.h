#pragma once
#include<vector>
class DSU
{
private:
	std::vector<int> parent;
	std::vector<int> rank;
public:
	DSU(int size);
	int find(int x);
	void unionSet(int x, int y);
	bool connected(int x, int y);
};

