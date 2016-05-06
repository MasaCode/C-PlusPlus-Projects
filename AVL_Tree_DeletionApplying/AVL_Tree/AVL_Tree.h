#pragma once

#include <iostream>
#include <algorithm>

#include "TreeNode.h"

using std::cin;
using std::cout;
using std::endl;


class AVL_Tree
{
public:
	AVL_Tree();
	~AVL_Tree();
	void InOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	
	
	void Display();
	bool isEmpty();

	void Insert(int& data);
	void Delete(int keyValue);


	bool Inserting(int& data);
	void deleteData(const int keyValue);


private:
	void inOrderTraversalHelper(TreeNode*);
	void preOrderTraversalHelper(TreeNode*);
	void postOrderTraversalHelper(TreeNode*);
	

	void setBalance(TreeNode *pointer);
	int height(TreeNode*);
	int difference(TreeNode *);
	TreeNode* rotateLeft(TreeNode* pointer);
	TreeNode* rotateRight(TreeNode* pointer);
	TreeNode* rotateRightLeft(TreeNode* pointer);
	TreeNode* rotateLeftRight(TreeNode* pointer);
	void rebalance(TreeNode* pointer);
	void DisplayHelper(TreeNode*, int);
	
	
private:
	TreeNode *_root;
};

