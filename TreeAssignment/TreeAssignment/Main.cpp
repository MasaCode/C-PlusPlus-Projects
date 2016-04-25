#include <iostream>
//#include <string>
#include "Tree.h"

using std::cout;
using std::cin;
using std::endl;

#define Max 100

void main(){
	Tree testTree;
	string inputMake, inputModel;
	int inputLotNumber, inputPrice;
	string decision;
	int count = 0;


	while (count != Max){
		if (decision == "Yes" || decision == "yes" || count == 0){
			cout << "Please enter the car Information of Car No." << count + 1 << endl;
			cout << "Lot Number :";
			cin >> inputLotNumber;
			cout << "Make : ";
			cin >> inputMake;
			cout << "Model : ";
			cin >> inputModel;
			cout << "Price : ";
			cin >> inputPrice;

			testTree.InsertNode(inputLotNumber, inputMake, inputModel, inputPrice);

			inputMake.clear();
			inputModel.clear();
			count++;
		}
		else if (decision == "no" || decision == "No"){
			break;
		}
		else{
			cout << "Wrong Input......" << endl;
			cout << "Please enter again." << endl;
		}

		decision.clear();
		cout << endl << "Do you wanna continue to input more?(yes/No) : ";
		cin >> decision;
	}



	cout << endl << "Doing Preorder traversal" << endl;
	testTree.preOrderTraversal();

	cout << endl << "Doing Inorder traversal" << endl;
	testTree.inOrderTraversal();

	cout << endl << "Doing Postorder traversal" << endl;
	testTree.postOrderTraversal();
}
