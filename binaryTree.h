#pragma once
#include"binTreeNode.h"
#include<iostream>
#include<vector>
//���������㷨
class binaryTree {
private:
	//���ĸ��ڵ�
	binTreeNode* mRoot;
	void clear(binTreeNode* node);
	int GetDepth(binTreeNode* root);
	void printTree(binTreeNode* node, std::string indent = "", bool isRight = true);
	void findPathDFS(binTreeNode* root, int target,int sum);
	std::vector<binTreeNode*> path;
public:
	binaryTree(binTreeNode* root = nullptr);
	~binaryTree();
	void insert(binTreeNode* parent, int value, bool isLeft);
	//�򵥵ع���һ�����԰���
	void buildCase();
	//��ӡ����
	void printTree();
	//�õ��������
	int depth();
	void findPath(int target);
};
