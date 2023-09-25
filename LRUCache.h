#pragma once
#include<unordered_map>
//双向链表节点
class Node {
public:
	int key, value;
	Node* prev, * next;
	Node(int k = 0, int v = 0);
};
class LRUCache {
private:
	//LRU缓存容量
	int mCapacity;
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