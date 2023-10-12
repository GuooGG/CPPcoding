#include "DSU.h"

DSU::DSU(int size)
{
	parent.resize(size);
	rank.resize(size, 0);
	for (int i = 0; i < size; i++) {
		parent[i] = i;
	}
}

int DSU::find(int x)
{
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void DSU::unionSet(int x, int y)
{
	int rootX = find(x);
	int rootY = find(y);
	if (rootX == rootY) return;
	if (rank[rootX] > rank[rootY]) {
		parent[rootY] = rootX;
	}
	else if (rank[rootX] < rank[rootY]) {
		parent[rootX] = rootY;
	}
	else {
		parent[rootY] = rootX;
		rank[rootX] += 1;
	}
	return;
}

bool DSU::connected(int x, int y)
{
	return find(x) == find(y);
}
