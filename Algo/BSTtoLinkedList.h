#pragma once
#include<iostream>
#include<queue>
//二叉搜索树原地转换为双向链表
//BST定义
struct BSTreeNode {
	int mValue;
	BSTreeNode* mLeft;
	BSTreeNode* mRight;
};
//构造Case
BSTreeNode* buildCase();
void dispose(BSTreeNode* root, BSTreeNode*& head, BSTreeNode*& tail);
BSTreeNode* BST2LinkedList(BSTreeNode* root);
void displayTree(BSTreeNode* root);
void displayLinkedList(BSTreeNode* root);
