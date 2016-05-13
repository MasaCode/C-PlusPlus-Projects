#include <iostream>
#include "Sort.h"

/*
int SetSize(){
	int size;
	cout << "How many element do you want?" << endl;
	cout << "->";
	std::cin >> size;
	return size;
}
*/


int Menu(){
	int input;
	cout << "\tMenu\t" << endl;
	cout << "01. Selection Sort" << endl;
	cout << "02. Insertion Sort" << endl;
	cout << "03. BubbleSort" << endl;
	cout << "04. TagSort" << endl;
	cout << "05. BucketSort" << endl;
	cout << "06. IndexSort" << endl;
	cout << "07. ShellSort" << endl;
	cout << "08. QuickSort" << endl;
	cout << "09. MergeSort" << endl;
	cout << "10. HeapSort" << endl;
	cout << "11. set the value " << endl;
	cout << "12. end" << endl;
	cout << "Input : ";
	std::cin >> input;
	return input;
}

void main(){
	Sort obj(21,100);
	bool isEnd = false;
	int menu;

	do{
		menu = Menu();
		switch (menu){
		case 1:
			obj.SelectionSort();
			break;
		case 2:
			obj.InsertionSort();
			break;
		case 3:
			obj.BubbleSort();
			break;
		case 4:
			obj.TagSort();
			break;
		case 5:
			obj.BucketSort();
			break;
		case 6:
			obj.IndexSort();
			break;
		case 7:
			obj.ShellSort();
			break;
		case 8:
			obj.QuickSort();
			break;
		case 9:
			obj.MergeSort();
			break;
		case 10:
			obj.HeapSort();
			break;
		case 11:
			obj.SetElement();
			break;
		default:
			isEnd = true;
			break;
		}
	} while (!isEnd);

}