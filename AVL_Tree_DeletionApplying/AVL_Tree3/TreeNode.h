#pragma once

class AVL_Tree;

class TreeNode{
	
	friend class AVL_Tree; //Need to check what it means.

public:
	TreeNode(int data) :_data(data),_height(1){
		_right = nullptr;
		_left = nullptr;
	}
	~TreeNode(){ 
		delete _right, _left; 
		_right = _left = 0;
	}

private:
	TreeNode *_left;
	TreeNode *_right;
	unsigned char _height;
	int _data;
};