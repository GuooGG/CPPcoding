#pragma once
#include<unordered_map>
#include"DoublyLinkedKeyNode.h"

class LRUCache {
private:
	//LRU��������
	int mCapacity;
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
