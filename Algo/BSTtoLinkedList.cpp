/*
BST2LinkedList
由二叉搜索树得到一个双向链表
输入一棵二元查找树，将该转换成个排 序的双向链表。
要求不能创建任何新的结点，只调整指针向。
10
/ \
6 14
/ \ / \
4 8 12 16
转换成双向链表
4=6=8=10=12=14=16
Date:2023/9/20
Coder:GuoGGo
*/

#include"BSTtoLinkedList.h"
//构造Case
BSTreeNode* buildCase() {
	BSTreeNode* root = new BSTreeNode();
	root->mValue = 10;
	root->mLeft = new BSTreeNode();
	root->mLeft->mValue = 6;
	root->mLeft->mLeft = new BSTreeNode();
	root->mLeft->mLeft->mValue = 4;
	root->mLeft->mRight = new BSTreeNode();
	root->mLeft->mRight->mValue = 8;
	root->mRight = new BSTreeNode();
	root->mRight->mValue = 14;
	root->mRight->mLeft = new BSTreeNode();
	root->mRight->mLeft->mValue = 12;
	root->mRight->mRight = new BSTreeNode();
	root->mRight->mRight->mValue = 16;
	return root;
}
//算法实现
void dispose(BSTreeNode* root, BSTreeNode*& head, BSTreeNode*& tail) {
	if (root == nullptr) {
		head = nullptr;
		tail = nullptr;
		return;
	}
	BSTreeNode* left = nullptr;
	BSTreeNode* right = nullptr;
	dispose(root->mLeft, head, left);
	dispose(root->mRight, right, tail);
	if (left == nullptr) {
		head = root;
	}
	else {
		left->mRight = root;
		root->mLeft = left;
	}
	if (right == nullptr) {
		tail = root;
	}
	else {
		right->mLeft = root;
		root->mRight = right;
	}
	return;
}
BSTreeNode* BST2LinkedList(BSTreeNode* root) {
	BSTreeNode* head = nullptr;
	BSTreeNode* tail = nullptr;
	dispose(root, head, tail);
	return head;
}
void displayTree(BSTreeNode* root)
{
	std::queue<BSTreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		size_t count = que.size();
		while (count--) {
			BSTreeNode* node = que.front();
			que.pop();
			if (node->mLeft!=nullptr) {
				que.push(node->mLeft);
			}
			if (node->mRight!=nullptr) {
				que.push(node->mRight);
			}
			std::cout << node->mValue << "\t";
		}
		std::cout << std::endl;
	}
}
void displayLinkedList(BSTreeNode* root) {
	BSTreeNode* traveller = root;
	while (traveller) {
		std::cout << traveller->mValue;
		if (traveller->mRight) {
			std::cout << "<=>";
		}
		traveller = traveller->mRight;
	}
}