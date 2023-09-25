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
	// �������ڵ�
	mRoot = new binTreeNode(1);

	// ���������ڵ�
	binTreeNode* node2 = new binTreeNode(2);
	binTreeNode* node3 = new binTreeNode(3);
	binTreeNode* node4 = new binTreeNode(4);
	binTreeNode* node5 = new binTreeNode(5);

	// ���ڵ���ӵ�����
	insert(mRoot, 2, true);  // ���ڵ�2���Ϊ���ڵ������
	insert(mRoot, 3, false); // ���ڵ�3���Ϊ���ڵ���Һ���
	insert(node2, 4, true);  // ���ڵ�4���Ϊ�ڵ�2������
	insert(node2, 5, false); // ���ڵ�5���Ϊ�ڵ�2���Һ���
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


int binaryTree::depth()
{
	return GetDepth(mRoot);
}

binaryTree::binaryTree(binTreeNode* root)
	:mRoot(root)
{

}

binaryTree::~binaryTree()
{
	clear(mRoot);
}
