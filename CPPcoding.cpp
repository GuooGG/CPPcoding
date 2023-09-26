#include <iostream>
#include"binaryTree.h"
using namespace std;
int main()
{
    binaryTree tree;
    tree.buildCase();
    tree.printTree();
    tree.findPath(22);
    return 0;
}
