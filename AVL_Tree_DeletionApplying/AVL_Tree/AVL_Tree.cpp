#include "AVL_Tree.h"

AVL_Tree::AVL_Tree() : _root(0)
{
}

AVL_Tree::~AVL_Tree(){
	delete _root;
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


 ////// Charenge /////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AVL_Tree::setBalance(TreeNode* pointer){
	pointer->_balance = difference(pointer);
}

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

	diff = rightHeight - leftHeight;
	return diff;
}

TreeNode* AVL_Tree::rotateLeft(TreeNode* pointer){
	TreeNode* temp = pointer->_right;
	temp->_parent = pointer->_parent;
	pointer->_right = temp->_left;

	if (pointer->_right != 0)
		pointer->_right->_parent = pointer;

	temp->_left = pointer;
	pointer->_parent = temp;

	if (temp->_parent != 0){
		if (temp->_parent->_right == pointer){
			temp->_parent->_right = temp;
		}
		else{
			temp->_parent->_left = temp;
		}
	}

	setBalance(pointer);
	setBalance(temp);

	return temp;
}

TreeNode* AVL_Tree::rotateRight(TreeNode* pointer){
	TreeNode* temp = pointer->_left;
	temp->_parent = pointer->_parent;
	pointer->_left = temp->_right;


	if (pointer->_left != 0)
		pointer->_left->_parent = pointer;

	temp->_right = pointer;
	pointer->_parent = temp;

	if (temp->_parent != 0){
		if (temp->_parent->_right == pointer){
			temp->_parent->_right = temp;
		}
		else{
			temp->_parent->_left = temp;
		}
	}

	setBalance(pointer);
	setBalance(temp);

	return temp;
}


TreeNode* AVL_Tree::rotateLeftRight(TreeNode* pointer){
	pointer->_left = rotateLeft(pointer->_left);
	return rotateRight(pointer);
}

TreeNode* AVL_Tree::rotateRightLeft(TreeNode* pointer){
	pointer->_right = rotateRight(pointer->_right);
	return rotateLeft(pointer);
}

void AVL_Tree::rebalance(TreeNode* pointer){
	setBalance(pointer);

	if (pointer->_balance == -2){
		if (height(pointer->_left->_left) >= height(pointer->_left->_right)){
			pointer = rotateRight(pointer);
		}
		else{
			pointer = rotateLeftRight(pointer);
		}
	}
	else if (pointer->_balance == 2){
		if (height(pointer->_right->_right) >= height(pointer->_right->_left)){
			pointer = rotateLeft(pointer);
		}
		else{
			pointer = rotateRightLeft(pointer);
		}
	}

	if (pointer->_parent != 0){
		rebalance(pointer->_parent);
	}
	else{
		_root = pointer;
	}
}


bool AVL_Tree::Inserting(int& data){
	if (_root == 0){
		_root = new TreeNode(data,0);
	}
	else{
		TreeNode *parent, *temp = _root;

		while (true){
			if (temp->_data == data)
				return false;

			parent = temp;
			bool goLeft = temp->_data > data;
			temp = goLeft ? temp->_left : temp->_right;

			if (temp == 0){
				if (goLeft){
					parent->_left = new TreeNode(data,parent);
				}
				else{
					parent->_right = new TreeNode(data, parent);
				}

				rebalance(parent);
				break;
			}
		}
	}

	return true;
}

void AVL_Tree::deleteData(const int keyValue){
	if (_root == 0)
		return;

	TreeNode *temp = _root, *parent = _root, *delNode = 0, *child = 0;
	
	while (child != 0){
		parent = temp;
		temp = child;
		child = keyValue >= temp->_data ? temp->_right : temp->_left;
		if (keyValue == temp->_data)
			delNode = temp;
	}

	if (delNode != 0){
		delNode->_data = temp->_data;

		child = temp->_left != 0 ? temp->_left : temp->_right;

		if (_root->_data == keyValue){
			_root = child;
		}
		else{
			if (parent->_left == temp){
				parent->_left = child;
			}
			else{
				parent->_right = child;
			}
			
			rebalance(parent);
		}
	}

}


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
			cout << "		";
		cout << pointer->_data;
		DisplayHelper(pointer->_left, level + 1);

	}
}

bool AVL_Tree::isEmpty(){
	return (_root == 0);
}

