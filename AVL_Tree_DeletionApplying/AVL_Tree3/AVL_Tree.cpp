#include "AVL_Tree.h"


AVL_Tree::AVL_Tree()
{
	_root = nullptr;
}


AVL_Tree::~AVL_Tree()
{
	delete _root;
}


unsigned char AVL_Tree::height(TreeNode* ptr){
	return ptr != nullptr ? ptr->_height : 0;
}

int AVL_Tree::balanceFactor(TreeNode* ptr){
	return (height(ptr->_right) - height(ptr->_left));
}

void AVL_Tree::fixedHeight(TreeNode* ptr){
	unsigned char heightR = height(ptr->_left);
	unsigned char heightL = height(ptr->_right);
	ptr->_height = ((heightR > heightL) ? heightR : heightL) + 1;
}

TreeNode* AVL_Tree::rotateRight(TreeNode* ptr){
	TreeNode* temp = ptr->_left;
	ptr->_left = temp->_right;

	temp->_right = ptr;

	fixedHeight(ptr);
	fixedHeight(temp);

	return temp;
}


TreeNode* AVL_Tree::rotateLeft(TreeNode* ptr){
	TreeNode* temp = ptr->_right;
	ptr->_right = temp->_left;

	temp->_left = ptr;

	fixedHeight(ptr);
	fixedHeight(temp);
	return temp;
}

TreeNode* AVL_Tree::balance(TreeNode* ptr){
	fixedHeight(ptr);
	
	if (balanceFactor(ptr) == 2){
		if (balanceFactor(ptr->_right) < 0)
			ptr->_right = rotateRight(ptr->_right);
		return rotateLeft(ptr);
	}
	else if (balanceFactor(ptr) == -2){
		if (balanceFactor(ptr->_left) > 0)
			ptr->_left = rotateLeft(ptr->_left);
		return rotateRight(ptr);
	}

	return ptr;
}

void AVL_Tree::insert(int data){
	_root = insert(data, _root);
}

TreeNode* AVL_Tree::insert(int data, TreeNode* ptr){
	if (ptr == nullptr){
		return (new TreeNode(data));
	}

	if (ptr->_data > data)
		ptr->_left = insert(data, ptr->_left);
	else
		ptr->_right = insert(data, ptr->_right);

	return balance(ptr);
}

TreeNode* AVL_Tree::findMin(TreeNode* ptr){
	return (ptr->_left == nullptr) ? ptr : findMin(ptr->_left);
}

TreeNode* AVL_Tree::removeMin(TreeNode* ptr){
	if (ptr->_left == nullptr)
		return ptr->_right;

	ptr->_left = removeMin(ptr->_left);
	return balance(ptr);
}

void AVL_Tree::remove(int data){
	_root = remove(data, _root);
}

TreeNode* AVL_Tree::remove(int data, TreeNode* ptr){
	if (ptr == nullptr){
		cout << "The data was not found.... " << endl;
		return 0;
	}

	if (ptr->_data > data){
		ptr->_left = remove(data, ptr->_left);
	}
	else if (ptr->_data < data){
		ptr->_right = remove(data, ptr->_right);
	}
	else{ //TODO : I need to make it work in case of delete tree has One right child, delete tree has two child.
		TreeNode* right = ptr->_right;
		TreeNode* left = ptr->_left;

		delete ptr; 
		ptr = nullptr;

		if (right == nullptr)
			return left;

		TreeNode* min = findMin(right);
		min->_right = removeMin(right);
		min->_left = left;


		return balance(min);
	}

	return balance(ptr);
}


void AVL_Tree::Display(){
	cout << endl << "Displaying the tree" << endl;
	DisplayHelper(_root,0);
	cout << endl << endl;
}

void AVL_Tree::DisplayHelper(TreeNode* pointer, int level){
	int i = 0;
	if (pointer != nullptr){
		DisplayHelper(pointer->_right, level + 1);
		cout << endl;
		if (pointer == _root)
			cout << "Root -> ";
		for (i = 0; i < level && pointer != _root; i++)
			cout << "		";
		cout << pointer->_data;
		DisplayHelper(pointer->_left, level + 1);

	}
}


bool AVL_Tree::isEmpty(){
	return (_root == nullptr);
}

///// InOrderTraversal //////////////////////////////////////////////////////////////////////////////////////////////////
void AVL_Tree::InOrderTraversal(){
	cout << endl << "InOrder Traversal Tree : ";
	inOrderTraversalHelper(_root);
	cout << endl << endl;
}

void AVL_Tree::inOrderTraversalHelper(TreeNode* pointer){
	if (pointer != nullptr){
		inOrderTraversalHelper(pointer->_left);
		cout << pointer->_data << " ";
		inOrderTraversalHelper(pointer->_right);
	}
}




///// PreOrderTraversal //////////////////////////////////////////////////////////////////////////////////////////////////
void AVL_Tree::PreOrderTraversal(){
	cout << endl << "PreOrder Traversal Tree : ";
	preOrderTraversalHelper(_root);
	cout << endl << endl;
}


void AVL_Tree::preOrderTraversalHelper(TreeNode* pointer){
	if (pointer != nullptr){
		cout << pointer->_data << " ";
		preOrderTraversalHelper(pointer->_left);
		preOrderTraversalHelper(pointer->_right);
	}
}


///// PostOrderTraversal //////////////////////////////////////////////////////////////////////////////////////////////////
void AVL_Tree::PostOrderTraversal(){
	cout << endl << "PostOrder Traversal Tree : ";
	postOrderTraversalHelper(_root);
	cout << endl << endl;
}

void AVL_Tree::postOrderTraversalHelper(TreeNode* pointer){
	if (pointer != nullptr){
		postOrderTraversalHelper(pointer->_left);
		postOrderTraversalHelper(pointer->_right);
		cout << pointer->_data << " ";
	}
}

////// Traversal Funcrions end /////////////////////////////////////////////////////////////////////////////////////////////////
