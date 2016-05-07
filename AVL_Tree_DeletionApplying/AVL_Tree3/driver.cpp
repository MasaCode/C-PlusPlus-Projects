#include "AVL_Tree.h"


int menu(){
	int input;
	cout << "   AVL Tree Menu" << endl;
	cout << "1. Insert data to tree" << endl;
	cout << "2. Dispay balanced AVL Tree" << endl;
	cout << "3. InOrder Traversal" << endl;
	cout << "4. PreOrder Traversal" << endl;
	cout << "5. PostOrder Traversal" << endl;
	cout << "6. Delete the data from tree" << endl;
	cout << "7. Exit" << endl;
	cout << "Your Input -> ";
	cin >> input;
	return input;
}


void main(){
	AVL_Tree avlTree;
	int input, data;
	while (true){
		input = menu();
		switch (input){
		case 1:
			cout << "Plase enter the data : ";
			cin >> data;
			avlTree.insert(data);
			break;
		case 2:
			if (avlTree.isEmpty()){
				cout << "The Tree is empty...." << endl;
				break;
			}
			avlTree.Display();
			break;
		case 3:
			if (avlTree.isEmpty()){
				cout << "The Tree is empty....." << endl;
				break;
			}
			avlTree.InOrderTraversal();
			break;
		case 4:
			if (avlTree.isEmpty()){
				cout << "The Tree is empty....." << endl;
				break;
			}
			avlTree.PreOrderTraversal();
			break;
		case 5:
			if (avlTree.isEmpty()){
				cout << "The Tree is empty....." << endl;
				break;
			}
			avlTree.PostOrderTraversal();
			break;
		case 6:
			cout << "Which element do you wanna delete" << endl;
			avlTree.InOrderTraversal();
			cout << "Your Input -> ";
			cin >> data;
			avlTree.remove(data);
			//cout << "I did not make it yet......" << endl;
			break;
		default:
			return;
		}
	}

}