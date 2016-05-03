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
	void Insert(int& data);
	void InOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	void Display();
	bool isEmpty();

private:
	void insertHelper(TreeNode** pointer, int& data);
	void inOrderTraversalHelper(TreeNode*);
	void preOrderTraversalHelper(TreeNode*);
	void postOrderTraversalHelper(TreeNode*);
	int height(TreeNode*);
	int difference(TreeNode *);
	TreeNode* RR_rotation(TreeNode* pivot);
	TreeNode* LL_rotation(TreeNode* pivot);
	TreeNode* LR_rotation(TreeNode* pivot);
	TreeNode* RL_rotation(TreeNode * pivot);
	TreeNode* balance(TreeNode*);
	void DisplayHelper(TreeNode*, int);

private:
	TreeNode *_root;
};

