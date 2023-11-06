#include <unordered_map>

class Node
{
public:
	int key, value, freq;
	Node *prev, *next;
	Node(int k = 0, int v = 0)
		: key(k), value(v), freq(1), prev(nullptr), next(nullptr)
	{
	}
};
class LRUCache
{
private:
	// LRU缓存容量
	size_t mCapacity;
	// dummmy哨兵节点,prev=tail,next=head;
	Node *dummy;
	// 哈希表->双向链表
	std::unordered_map<int, Node *> keyToNode;
	// 删除一个元素
	void remove(Node *node);
	// 在链头插入元素
	void push(Node *node);
	// hashmap_to_linkedlist
	Node *getNode(int key);

public:
	LRUCache(int capacity);
	int get(int key);
	void put(int key, int value);
};

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
	, dummy(new Node())
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
