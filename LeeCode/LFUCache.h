#pragma once
//LeeCode.460 LFUCache
//Date:2023/9/25 14:18

#include<unordered_map>
class Node {
public:
	int key, value, freq;
	Node* prev, * next;
	Node(int k = 0, int v = 0) 
		:key(k)
		,value(v)
		,freq(1)
		,prev(nullptr)
		,next(nullptr)
	{}
};
class LFUCache {
private:
	int mCapacity;
	int minFreq;
	std::unordered_map<int, Node*> keyToNode;
	std::unordered_map<int, Node*> freqToDummy;
	Node* getNode(int key);
	Node* newList();
	//在链表头添加一个节点
	void push(int freq,Node* node);
	void remove(Node* node);
public:
	LFUCache(int capacity);
	int get(int key);
	void put(int key, int value);
};
