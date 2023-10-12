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
	//LRU��������
	size_t mCapacity;
	//dummmy�ڱ��ڵ�,prev=tail,next=head;
	Node* dummy;
	//��ϣ��->˫������
	std::unordered_map<int, Node*> keyToNode;
	//ɾ��һ��Ԫ��
	void remove(Node* node);
	//����ͷ����Ԫ��
	void push(Node* node);
	//hashmap_to_linkedlist
	Node* getNode(int key);
public:
	LRUCache(int capacity);
	int get(int key);
	void put(int key, int value);
};
