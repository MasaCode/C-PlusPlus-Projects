#pragma once

class AVL_Tree;

class TreeNode{
	
	friend class AVL_Tree; //Need to check what it means.

public:
	TreeNode(int data,TreeNode* parent) : _right(0), _left(0),_data(data),_balance(0),_parent(parent){}
	~TreeNode(){ delete _right, _left; }

private:
	TreeNode *_left;
	TreeNode *_right;
	TreeNode *_parent;
	int _data;
	int _balance;
};