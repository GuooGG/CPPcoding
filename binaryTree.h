#pragma once
#include"binTreeNode.h"
#include<iostream>
//���������㷨�����
class binaryTree {
private:
	//���ĸ��ڵ�
	binTreeNode* mRoot;
	void clear(binTreeNode* node);
	int GetDepth(binTreeNode* root);
	void printTree(binTreeNode* node, std::string indent = "", bool isRight = true);
public:
	binaryTree(binTreeNode* root = nullptr);
	~binaryTree();
	void insert(binTreeNode* parent, int value, bool isLeft);
	//�򵥵ع���һ�����԰���
	void buildCase();
	//��ӡ����
	void printTree();
	//�õ�����
	int depth();
};
