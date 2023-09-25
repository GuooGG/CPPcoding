#include"LRUCache.h"

Node::Node(int k, int v)
	:key(k)
	,value(v)
{
	prev = this;
	next = this;
}

void LRUCache::remove(Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void LRUCache::push(Node* node)
{
	node->prev = dummy;
	node->next = dummy->next;
	node->prev->next = node;
	node->next->prev = node;
}

Node* LRUCache::getNode(int key)
{
	auto it = keyToNode.find(key);
	if (it == keyToNode.end()) {
		return nullptr;
	}
	Node* node = it->second;
	remove(node);
	push(node);
	return node;
}

LRUCache::LRUCache(int capacity)
	:mCapacity(capacity)
	,dummy(new Node())
{
	dummy->prev = dummy;
	dummy->next = dummy;
}

int LRUCache::get(int key)
{
	Node* node = getNode(key);
	if (node == nullptr) {
		return -1;
	}
	return node->value;
}

void LRUCache::put(int key, int value)
{
	Node* node = getNode(key);
	if (node) {
		node->value = value;
		return;
	}
	node = new Node(key, value);
	keyToNode.insert(std::make_pair(key, node));
	push(node);
	if (keyToNode.size() > mCapacity) {
		auto backNode = dummy->prev;
		keyToNode.erase(backNode->key);
		remove(backNode);
		delete backNode;
	}

}
