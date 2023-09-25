#include"DoublyLinkedKeyNode.h"
Node::Node(int k, int v)
	:key(k)
	,value(v)
{
	next = this;
	prev = this;
	freq = 1;
}