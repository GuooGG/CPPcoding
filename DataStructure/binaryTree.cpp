#include"binaryTree.h"

void binaryTree::clear(binTreeNode* node)
{
	if (node != nullptr) {
		clear(node->mLeft);
		clear(node->mRight);
		delete node;
	}
}

int binaryTree::GetDepth(binTreeNode* root)
{
	if (root == nullptr) {
		return 0;
	}
	int leftDepth = 1 + GetDepth(root->mLeft);
	int rightDepth = 1 + GetDepth(root->mRight);
	return std::max(leftDepth, rightDepth);
}

void binaryTree::insert(binTreeNode* parent, int value, bool isLeft)
{
	binTreeNode* node = new binTreeNode(value);
	if (isLeft) {
		parent->mLeft = node;
	}
	else {
		parent->mRight = node;
	}
}

void binaryTree::buildCase()
{
	// 创建根节点
	mRoot = new binTreeNode(10);
	mRoot->mLeft = new binTreeNode(5);
	mRoot->mRight = new binTreeNode(12);
	mRoot->mLeft->mLeft = new binTreeNode(4);
	mRoot->mLeft->mRight = new binTreeNode(7);
	//mRoot->mRight->mLeft = new binTreeNode(6);
	//mRoot->mRight->mRight = new binTreeNode(7);
}

void binaryTree::printTree()
{
	printTree(mRoot);
}


void binaryTree::printTree(binTreeNode* node, std::string indent, bool isRight)
{
	if (node != nullptr) {
		printTree(node->mRight, indent + (isRight ? "        " : "|       "), true);
		std::cout << indent;
		if (isRight) {
			std::cout << " /";
		}
		else {
			std::cout << " \\";
		}
		std::cout << "----- " << node->mValue << std::endl;
		printTree(node->mLeft, indent + (isRight ? "|       " : "        "), false);
	}
}

void binaryTree::findPathDFS(binTreeNode* root, int target, int sum)
{
	if (root == nullptr)return;
	sum += root->mValue;
	path.push_back(root);
	if (root->mLeft==nullptr&&root->mRight==nullptr) {
		if (sum == target) {
			for (auto node : path) {
				std::cout << node->mValue << "\t";
			}
		}
	}else {
		if (root->mLeft) {
			findPathDFS(root->mLeft, target, sum);
		}
		if (root->mRight) {
			findPathDFS(root->mRight, target, sum);
		}
	}
	path.pop_back();
	sum -= root->mValue;
}


int binaryTree::depth()
{
	return GetDepth(mRoot);
}

void binaryTree::findPath(int target)
{
	findPathDFS(mRoot, target, 0);
}

binaryTree::binaryTree(binTreeNode* root)
	:mRoot(root)
{

}

binaryTree::~binaryTree()
{
	clear(mRoot);
}
