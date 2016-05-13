#ifndef TREE_H
#define TREE_H
#include <string>

class TreeNode{
	friend class Tree;
public:
	TreeNode(int &_data) :data(_data), left(0), right(0){

	}
	~TreeNode(){
		delete left, right;
	}

private:
	int data;
	TreeNode *left;
	TreeNode *right;
};



class Tree{
public:
	Tree();
	~Tree();
	void Insert(int&,std::string);
	void GetOrder(int[]);

private:
	TreeNode *root;

	void InsertHelper(TreeNode **, int&);
	void GetOrderHelper(TreeNode *,int,int[]);
};


Tree::Tree(){
	root = 0;
}


Tree::~Tree(){
	delete root;
}

void Tree::Insert(int &data, std::string direction){
	if (root = 0)
		root = new TreeNode(data);
	else{
		if (direction == "Right")
			InsertHelper(&(root->right), data);
		else if (direction == "Left")
			InsertHelper(&(root->left), data);

	}
}


void Tree::InsertHelper(TreeNode **ptr, int &_data){
	if (*ptr == 0)
		*ptr = new TreeNode(_data);
	else{
		if (_data < (*ptr)->data)
			InsertHelper(&((*ptr)->left), _data);
		else if (_data >(*ptr)->data)
			InsertHelper(&((*ptr)->right), _data);
	}
}


void Tree::GetOrder(int output[]){
	int count = 0;
	GetOrderHelper(root,count,output);
}

void Tree::GetOrderHelper(TreeNode *ptr,int count,int output[]){
	if (ptr != 0){
		GetOrderHelper(ptr->left, count, output);
		output[count] = ptr->data;
		count++;
		GetOrderHelper(ptr->right, count, output);
	}
}


#endif