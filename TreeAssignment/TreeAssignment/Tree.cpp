#include "Tree.h"

Tree::Tree(){
	root = 0;
}


//Writing data into file
void Tree::WriteFile(char *fileName,int lotNumber,string make,string model,int price){
	FILE *fw = fopen(fileName, "a");
	fprintf(fw, "%d %s %s %d\n", lotNumber, make.c_str(), model.c_str(), price);
	fclose(fw);
}

//Inserting....
void Tree::InsertNode(int &lotNumber, string &make, string &model, int &price){
	insertHelper(&root, lotNumber, make, model, price);
}

void Tree::insertHelper(TreeNode **pointer, int &lotNumber, string &make, string &model, int &price){
	if (*pointer == 0){
		*pointer = new TreeNode(lotNumber, make, model, price);
	}
	else{
		if (lotNumber < (*pointer)->LotNumber()){
			insertHelper(&((*pointer)->left), lotNumber, make, model, price);
		}
		else if (lotNumber >(*pointer)->LotNumber()){
			insertHelper(&((*pointer)->right), lotNumber, make, model, price);
		}
		else if (lotNumber == (*pointer)->LotNumber()){
			insertHelper(&((*pointer)->middle), lotNumber, make, model, price);
		}
	}
}

//Traversal Functions

//PreOrderTraversal
void Tree::preOrderTraversal(){
	preOrderHelper(root);
}

void Tree::preOrderHelper(TreeNode *pointer){
	if (pointer != 0){
		WriteFile("PreOrderTraversal.txt", pointer->LotNumber(),pointer->Make(), pointer->Model(), pointer->Price());
		preOrderHelper(pointer->left);
		preOrderHelper(pointer->middle);
		preOrderHelper(pointer->right);
	}
}


//InOrderTraversal
void Tree::inOrderTraversal(){
	inOrderHelper(root);
}

void Tree::inOrderHelper(TreeNode *pointer){
	if (pointer != 0){
		inOrderHelper(pointer->left);
		inOrderHelper(pointer->middle);
		WriteFile("InOrderTraversal.txt", pointer->LotNumber(), pointer->Make(), pointer->Model(), pointer->Price());
		inOrderHelper(pointer->right);
	}
}


//PostOrderTraversal
void Tree::postOrderTraversal(){
	postOrderHelper(root);
}

void Tree::postOrderHelper(TreeNode *pointer){
	if (pointer != 0){
		postOrderHelper(pointer->left);
		postOrderHelper(pointer->middle);
		postOrderHelper(pointer->right);
		WriteFile("PostOrderTraversal.txt", pointer->LotNumber(), pointer->Make(), pointer->Model(), pointer->Price());
	}
}