#include "BinarySearchTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}
void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);
	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BinarySearchTree::Print_Inorder(Node* node)
{

	if (node == nullptr)
		return;

	cout << node->key << endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
	
}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left)
		node = node->left;
	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
		node = node->right;
	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);
	Node* parant = node->parant;

	while (parant && node == parant->right)
	{
		node = parant;
		parant = parant->parant;
	}

	return parant;
}

void BinarySearchTree::insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parant = nullptr;

	while (node)
	{
		parant = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parant = parant;
	if (key < parant->key)
		parant->left = newNode;
	else
		parant->right = newNode;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
		Replace(node, node->right);
	else if (node->right == nullptr)
		Replace(node, node->left);
	else
	{
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

//u 서브트리를 v 서브트리로 교체
//그리고 delete u
void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parant == nullptr)
		_root = v;
	else if (u == u->parant->left)
		u->parant->left = v;
	else
		u->parant->right = v;

	if (v)
		v->parant = u->parant;

	delete u;
}
