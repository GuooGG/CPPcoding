#include"LFUCache.h"

Node* LFUCache::getNode(int key)
{
	auto it = keyToNode.find(key);
	if (it == keyToNode.end()) {
		return nullptr;
	}
	auto node = it->second;
	remove(node);
	auto dummy = freqToDummy[node->freq];
	if (dummy->prev == dummy) {
		if (minFreq == node->freq) {
			minFreq++;
		}
	}
	node->freq = (node->freq) + 1;
	push(node->freq, node);
}

Node* LFUCache::newList()
{
	auto newDummy = new Node();
	return newDummy;

}

void LFUCache::push(int freq, Node* node)
{
	auto it = freqToDummy.find(freq);
	if (it == freqToDummy.end()) {
		freqToDummy.emplace(freq,newList());
		it = freqToDummy.find(freq);		
	}
	auto dummy = it->second;
	node->prev = dummy;
	node->next = dummy->next;
	node->prev->next = node;
	node->next->prev = node;
}

void LFUCache::remove(Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

LFUCache::LFUCache(int capacity)
	:mCapacity(capacity)
	,minFreq(INT32_MAX)
{
}

int LFUCache::get(int key)
{
	auto node = getNode(key);
	return node ? node->value : -1;
}

void LFUCache::put(int key, int value)
{
	auto node = getNode(key);
	if (node) {
		node->value = value;
		return;
	}
	if (keyToNode.size() == mCapacity) 
	{
		auto dummy = freqToDummy[minFreq];
		auto backNode = dummy->prev;
		keyToNode.erase(backNode->key);
		remove(backNode);
		delete backNode;
	}
	Node* node = new Node(key, value);
	keyToNode[key] = node;
	push(1, node);
	minFreq = 1;
}
