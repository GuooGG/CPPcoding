#pragma once
//DoublyLinkedKeyNode
//˫������ڵ㣬���������ڲ�Ԫ��
class Node {
public:
	int key, value,freq;
	Node* prev, * next;
	Node(int k = 0, int v = 0);
};