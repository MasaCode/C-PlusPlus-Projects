#ifndef TREE_H
#define TREE_H

#include <new>
#include <stdio.h>
#include <iostream>
#include "TreeNode.h"

using std::cout;
using std::endl;

class Tree{
public:
	Tree();
	void preOrderTraversal();
	void inOrderTraversal();
	void postOrderTraversal();
	void InsertNode(int&, string&, string&, int&);

private:
	TreeNode *root;
	void insertHelper(TreeNode **, int&, string&, string&, int&);
	void preOrderHelper(TreeNode *);
	void inOrderHelper(TreeNode *);
	void postOrderHelper(TreeNode *);
	void WriteFile(char *,int,string,string,int);

};

#endif