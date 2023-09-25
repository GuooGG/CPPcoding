#pragma once
//LeeCode.460 LFUCache
//Date:2023/9/25 14:18
//Author:GGO
#include"DoublyLinkedKeyNode.h"
#include<unordered_map>
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
