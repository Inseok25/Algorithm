#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree bst;

	bst.insert(20);
	bst.insert(10);
	bst.insert(30);
	bst.insert(25);
	bst.insert(40);
	bst.insert(26);
	bst.insert(50);

	bst.Delete(20);
	bst.Print();
}