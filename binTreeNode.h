#pragma once
//二叉树节点类
class binTreeNode
{
public:
	binTreeNode(int val,binTreeNode* left = nullptr,binTreeNode* right = nullptr);
	int mValue;
	binTreeNode* mLeft;
	binTreeNode* mRight;
};