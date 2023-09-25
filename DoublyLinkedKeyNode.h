#pragma once
//DoublyLinkedKeyNode
//双向链表节点，带键与多个内部元素
class Node {
public:
	int key, value,freq;
	Node* prev, * next;
	Node(int k = 0, int v = 0);
};