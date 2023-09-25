#pragma once
#include"binTreeNode.h"
#include<iostream>
//二叉树简单算法题汇总
class binaryTree {
private:
	//树的根节点
	binTreeNode* mRoot;
	void clear(binTreeNode* node);
	int GetDepth(binTreeNode* root);
	void printTree(binTreeNode* node, std::string indent = "", bool isRight = true);
public:
	binaryTree(binTreeNode* root = nullptr);
	~binaryTree();
	void insert(binTreeNode* parent, int value, bool isLeft);
	//简单地构造一个测试案例
	void buildCase();
	//打印出树
	void printTree();
	//得到树深
	int depth();
};
