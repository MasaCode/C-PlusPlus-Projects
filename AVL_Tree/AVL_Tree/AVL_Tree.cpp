#include "AVL_Tree.h"

AVL_Tree::AVL_Tree() : _root(0)
{
}

AVL_Tree::~AVL_Tree(){
	delete _root;
}


///// Insertion //////////////////////////////////////////////////////////////////////////////////////////////////
void AVL_Tree::Insert(int& data){
	insertHelper(&_root, data);
}

void AVL_Tree::insertHelper(TreeNode** pointer, int& data){
	if (*pointer == 0)
		*pointer = new TreeNode(data);
	else{
		if ((*pointer)->_data > data){
			insertHelper(&((*pointer)->_left), data);
			*pointer = balance(*pointer);
		}else{
			insertHelper(&((*pointer)->_right), data);
			*pointer = balance(*pointer);
		}
	}
}


///// InOrderTraversal //////////////////////////////////////////////////////////////////////////////////////////////////
void AVL_Tree::InOrderTraversal(){
	cout << endl << "InOrder Traversal Tree : ";
	inOrderTraversalHelper(_root);
	cout << endl << endl;
}

void AVL_Tree::inOrderTraversalHelper(TreeNode* pointer){
	if (pointer != 0){
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
	if (pointer != 0){
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
	if (pointer != 0){
		postOrderTraversalHelper(pointer->_left);
		postOrderTraversalHelper(pointer->_right);
		cout << pointer->_data << " ";
	}
}

////// Traversal Funcrions end /////////////////////////////////////////////////////////////////////////////////////////////////

///// Balancing the tree //////////////////////////////////////////////////////////////////////////////////////////////////////
int AVL_Tree::height(TreeNode* pointer){
	int h = 0;
	if (pointer != 0){
		int leftHeight = height(pointer->_left);
		int rightHeight = height(pointer->_right);
		h = std::max(leftHeight, rightHeight) + 1;
	}
	return h;
}

int AVL_Tree::difference(TreeNode* pointer){
	int diff = 0;
	int leftHeight = height(pointer->_left);
	int rightHeight = height(pointer->_right);

	diff = leftHeight - rightHeight;
	return diff;
}


TreeNode* AVL_Tree::RR_rotation(TreeNode* pivot){
	TreeNode* temp;
	temp = pivot->_right;
	pivot->_right = temp->_left;
	temp->_left = pivot;
	return temp;
}

TreeNode* AVL_Tree::LL_rotation(TreeNode* pivot){
	TreeNode* temp;
	temp = pivot->_left;
	pivot->_left = temp->_right;
	temp->_right = pivot;
	return temp;
}

TreeNode* AVL_Tree::LR_rotation(TreeNode* pivot){
	TreeNode* temp;
	temp = pivot->_left;
	pivot->_left = RR_rotation(temp);

	return LL_rotation(pivot);
}

TreeNode* AVL_Tree::RL_rotation(TreeNode* pivot){
	TreeNode* temp;
	temp = pivot->_right;
	pivot->_right = LL_rotation(temp);

	return RR_rotation(pivot);
}

TreeNode* AVL_Tree::balance(TreeNode* pointer){
	int diff = difference(pointer);

	if (diff > 1){
		
		if (difference(pointer->_left) > 0)
			pointer = LL_rotation(pointer);
		else
			pointer = LR_rotation(pointer);

	}else if (diff < -1){

		if (difference(pointer->_right))
			pointer = RL_rotation(pointer);
		else{
			pointer = RR_rotation(pointer);
		}

	}

	return pointer;
}

/////// Balancing the tree until here ///////////////////////////////////////////////////////////////////////////////

void AVL_Tree::Display(){
	cout << endl << "Displaying the Tree" << endl;
	DisplayHelper(_root, 0);
	cout << endl << endl;
}

void AVL_Tree::DisplayHelper(TreeNode* pointer, int level){
	int i = 0;
	if (pointer != 0){
		DisplayHelper(pointer->_right, level + 1);
		cout << endl;
		if (pointer == _root)
			cout << "Root -> ";
		for (i = 0; i < level && pointer != _root; i++)
			cout << "	e32";
		cout << pointer->_data;
		DisplayHelper(pointer->_left, level + 1);

	}
}

bool AVL_Tree::isEmpty(){
	return (_root == 0);
}