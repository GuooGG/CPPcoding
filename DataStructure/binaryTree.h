#pragma once
#include"binTreeNode.h"
#include<iostream>
#include<vector>
//二叉树简单算法

class binaryTree {
private:
	//树的根节点
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
	//简单地构造一个测试案例
	void buildCase();
	//打印出树
	void printTree();
	//得到树的深度
	int depth();
	void findPath(int target);
};
