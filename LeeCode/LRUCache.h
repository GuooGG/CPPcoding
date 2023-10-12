#pragma once
//LeeCode.146 LRUCache
//Date:2023/9/26 13:00
#include<unordered_map>

class Node {
public:
	int key, value, freq;
	Node* prev, * next;
	Node(int k = 0, int v = 0)
		:key(k)
		, value(v)
		, freq(1)
		, prev(nullptr)
		, next(nullptr)
	{}
};
class LRUCache {
private:
	//LRU缓存容量
	size_t mCapacity;
	//dummmy哨兵节点,prev=tail,next=head;
	Node* dummy;
	//哈希表->双向链表
	std::unordered_map<int, Node*> keyToNode;
	//删除一个元素
	void remove(Node* node);
	//在链头插入元素
	void push(Node* node);
	//hashmap_to_linkedlist
	Node* getNode(int key);
public:
	LRUCache(int capacity);
	int get(int key);
	void put(int key, int value);
};
