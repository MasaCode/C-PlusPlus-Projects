#pragma once

#include <iostream>
#include "TreeNode.h"

using std::cin;
using std::cout;
using std::endl;


class AVL_Tree
{
public:
	AVL_Tree();
	~AVL_Tree();
	void insert(int data);
	void remove(int data);
	void Display();
	void InOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	bool isEmpty();

private:
	unsigned char height(TreeNode* ptr);
	int balanceFactor(TreeNode* ptr);
	void fixedHeight(TreeNode* ptr);
	TreeNode* rotateRight(TreeNode* ptr);
	TreeNode* rotateLeft(TreeNode* ptr);
	TreeNode* balance(TreeNode* ptr);
	TreeNode* insert(int data,TreeNode* ptr);
	TreeNode* findMin(TreeNode* ptr);
	TreeNode* removeMin(TreeNode* ptr);
	TreeNode* remove(int data, TreeNode* ptr);

	void DisplayHelper(TreeNode*, int);
	void inOrderTraversalHelper(TreeNode*);
	void preOrderTraversalHelper(TreeNode*);
	void postOrderTraversalHelper(TreeNode*);

private:
	TreeNode* _root;
};

