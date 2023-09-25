
#include <iostream>
#include"BST2LinkedList.h"
using namespace std;
int main()
{
    BSTreeNode* test =  buildCase();
    displayTree(test);
    std::cout << "=====================" << std::endl;
    displayLinkedList(BST2LinkedList(test));
    return 0;
}
