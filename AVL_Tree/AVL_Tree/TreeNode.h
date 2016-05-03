#pragma once

class AVL_Tree;

class TreeNode{
	
	friend class AVL_Tree; //Need to check what it means.

public:
	TreeNode(int data) : _right(0), _left(0),_data(data){}
	~TreeNode(){ delete _right, _left; }

private:
	TreeNode *_left;
	TreeNode *_right;
	int _data;
};