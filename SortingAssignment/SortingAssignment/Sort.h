#ifndef SORT_H
#define SORT_H
#include <iostream>

using std::cout;
using std::endl;

#define MaxNumber 100

class Sort{
public:
		Sort();
		Sort(int,int);
		~Sort();

		void SetElement();
		void SelectionSort();
		void InsertionSort();
		void BubbleSort();
		void TagSort();
		void BucketSort(); 
		void IndexSort();
		void ShellSort();

		void QuickSort();
		void MergeSort();
		void HeapSort();

private:
	void CreateRandomNumber();
	void Print();
	void QuickSortHelper(int, int);
	int SeparatePosition(int, int);
	void Merge(int, int,int);
	void MergeSortHelper(int, int);
	
	void swap(int index1, int index2);
	void createHeap();
	void heapify(int currentIndex,int MinRange);
	void HeapSortHelper();

	int *input;
	int size;
	int Max;
	bool isSet;
};



#endif