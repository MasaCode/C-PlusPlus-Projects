#include "Sort.h"
#include <math.h>
#include <time.h>
#include <algorithm>

Sort::Sort(){
	size = 20;
	Max = 100;
	input = new int[size]; //Created the Array.
	isSet = false;
}

Sort::Sort(int _size,int _max){
	size = _size > 0 ? _size : 20;
	Max = _max > 0 ? _max : 100;
	input = new int[size]; //Created the Array.
	isSet = false;
}

Sort::~Sort(){
	delete[] input;
}

void Sort::SetElement(){
	int _size,count=0,temp;
	cout << "How many elements do you wanna? : ";
	std::cin >> _size;
	size = _size > 0 ? _size : 10;
	delete[] input;
	input = new int[size];

	do{
		cout << "Element " << count + 1 << " : ";
		std::cin >> temp;
		if (temp > 0){
			input[count] = temp;
			count++;
		}
		else{
			cout << "You enter wrong number...." << endl;
		}
	} while (count < size);

	isSet = true;
}

void Sort::Print(){
	cout << "Sorted numbers    : ";
	for (int i = 0; i < size; i++){
		cout << input[i] << " ";
		input[i] = -1; //Reseting the Array to get ready to be filled randomnumber.
	}
	cout << endl << endl;

}

void Sort::CreateRandomNumber(){
	int temp, count = 0, j;
	bool isValid = true;

	if (isSet)
		return;

	srand(time(NULL));

	do{
		temp = rand() % MaxNumber;

		for (j = 0; j < count; j++){
			if (temp == input[j]){
				isValid = false;
				break;
			}
		}

		if (isValid){
			input[count] = temp;
			count++;
		}

		isValid = true;
	} while (count < size);

	cout << endl << "Generated numbers : ";
	for (count = 0; count < size; count++)
		cout << input[count] << " ";
	cout << endl;

}


void Sort::SelectionSort(){
	int i = 0, j = 0,minPos = 0,temp;
	
	CreateRandomNumber();

	for (i = 0; i < size-1; i++){
		minPos = i;
		for (j = i+1; j < size; j++){
			if (input[minPos] > input[j])
				minPos = j;
		}

		if (minPos != i){
			temp = input[minPos];
			input[minPos] = input[i];
			input[i] = temp;
		}
	}

	Print();

}

void Sort::InsertionSort(){
	int i = 0, j = 0, temp;

	CreateRandomNumber();

	for (; i < size; i++){
		j = i;
		while (j > 0 && input[j] < input[j - 1]){
			temp = input[j];
			input[j] = input[j - 1];
			input[j - 1] = temp;
			j--;
		}
	}
	Print();
}

void Sort::BubbleSort(){
	int i = 0, j = 0,temp;

	CreateRandomNumber();

	for (i = 0; i < size - 1; i++){
		for (j = 0; j < size - i - 1; j++){
			if (input[j] > input[j + 1]){
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}

	Print();

}

void Sort::TagSort(){
	int i = 0, j = 0,minIndex;
	int *indexArray = new int[size];
	int *tempArray = new int[size];

	CreateRandomNumber();

	for (; i < size; i++)
		tempArray[i] = input[i];

	for (i = 0; i < size; i++){
		minIndex = i;
		for (j = 0; j < size; j++){
			if (input[minIndex] > input[j])
				minIndex = j;
		}

		indexArray[i] = minIndex;
		input[minIndex] = 999;
	}

	for (i = 0; i < size; i++)
		input[i] = tempArray[indexArray[i]];

	delete[] indexArray, tempArray;

	Print();
}

void Sort::BucketSort(){
	int i,j,arrayCount, digitCount,MaxInput = MaxNumber - 1, digit = 0;
	CreateRandomNumber();

	do{
		digit++;
		MaxInput /= 10;
	} while (MaxInput > 0);
	
	arrayCount = (int)pow(10, digit-1);

	//Creating array
	int **DigitArray = new int*[arrayCount];
	for (i = 0; i < arrayCount; i++)
		DigitArray[i] = new int[size];
	//finished creating array

	for (i = 0; i < arrayCount; i++){
		digitCount = 0;
		for (j = 0; j < size; j++){
			if ((input[j] % arrayCount) == i){
				DigitArray[i][digitCount] = input[j];
				digitCount++;
			}

		}
	}

	digitCount = 0;
	for (int m = 0; m < arrayCount; m++){
		for (i = 0; i < arrayCount; i++){
			for (j = 0; j < size; j++){
				if (DigitArray[i][j] < 0)
					break;
				if ((DigitArray[i][j] / arrayCount) == m){
					input[digitCount] = DigitArray[i][j];
					digitCount++;
				}
			}
		}
	}


	//Deleting array
	for (i = 0; i < arrayCount; i++)
		delete[] DigitArray[i];
	delete[] DigitArray;
	//finished deleting array

	Print();
}

void Sort::IndexSort(){
	int i = 0, max = 0, count = 0;

	CreateRandomNumber();

	for (; i < size; i++){
		if (max < input[i])
			max = input[i];
	}
	
	int *indexArray = new int[max + 1];

	for (int i = 0; i < max + 1; i++){
		indexArray[i] = -99;
	}

	for (i = 0; i < size; i++)
		indexArray[input[i]] = input[i];

	for (i = 0; i < max + 1; i++){
		if (indexArray[i] != -99){
			input[count] = indexArray[i];
			count++;
		}
	}

	delete[] indexArray;

	Print();
}


void Sort::ShellSort(){
	int i = 0, j = 0, temp, step;

	CreateRandomNumber();

	for (step = size / 2; step > 0; step /= 2){
		for (i = step; i < size; i++){
			temp = input[i];
			for (j = i; j >= step; j -= step){
				if (temp < input[j - step])
					input[j] = input[j - step];
				else
					break;
			}
			input[j] = temp;
		}
	}
	Print();
}

void Sort::QuickSort(){
	CreateRandomNumber();
	QuickSortHelper(0, size-1);
	Print();
}


void Sort::QuickSortHelper(int left, int right){
	int _separatePosition;
	if (left < right){
		_separatePosition = SeparatePosition(left, right);
		QuickSortHelper(left, _separatePosition - 1);
		QuickSortHelper(_separatePosition + 1, right);
	}
}

int Sort::SeparatePosition(int left, int right){
	int pivot = input[left];
	int leftCount = left + 1, rightCount = right;
	int switchPosition;
	while (!(leftCount == rightCount || leftCount > rightCount)){
		if (input[leftCount] < pivot)
			leftCount++;
		if (input[rightCount] > pivot)
			rightCount--;

		if (leftCount == rightCount || leftCount > rightCount)
			break;

		if (input[leftCount] > pivot && input[rightCount] < pivot){
			std::swap(input[leftCount], input[rightCount]);
			leftCount++;
			rightCount--;
		}
	}

	switchPosition = (input[rightCount] > pivot) ? rightCount - 1 : rightCount;
	std::swap(input[left], input[switchPosition]);
	return switchPosition;
}


void Sort::MergeSort(){
	CreateRandomNumber();
	MergeSortHelper(0, size - 1);
	Print();
}

void Sort::MergeSortHelper(int left, int right){
	int half;
	if (left < right){
		half = (left + right) / 2;
		MergeSortHelper(left, half);
		MergeSortHelper(half + 1, right);
		Merge(left, right, half);
	}
}

void Sort::Merge(int left, int right, int half){
	int temp, i = left, j = half + 1, s;
	int count = 0, *tempbox = new int[(right - left) + 1];


	while (i <= half || j <= right){
		if (i <= half && j <= right){
			if (input[i] > input[j]){
				tempbox[count] = input[j];
				count++;
				j++;
			}
			else if (input[i] < input[j]){
				tempbox[count] = input[i];
				count++;
				i++;
			}
		}

		if (i > half && j <= right){
			tempbox[count] = input[j];
			count++;
			j++;
		}
		else if (i <= half && j > right){
			tempbox[count] = input[i];
			count++;
			i++;
		}
	}

	for (i = left; i <= right; i++)
		input[i] = tempbox[i - left];

	delete[] tempbox;
}

void Sort::HeapSort(){
	CreateRandomNumber();
	HeapSortHelper();
	Print();
}

void Sort::HeapSortHelper(){
	createHeap();
	for (int i = size - 1; i > 0; i--){
		swap(0, i);
		heapify(0, i);
	}


}

void Sort::createHeap(){
	for (int i = (size - 1) / 2; i >= 0; i--)
		heapify(i,size);
}

void Sort::heapify(int current,int maxRange){
	int smallIndex, leftIndex, rightIndex;
	leftIndex = current * 2;
	rightIndex = current * 2 + 1;

	if ((leftIndex < maxRange) && (input[leftIndex] > input[current]))
		smallIndex = leftIndex;
	else
		smallIndex = current;
	
	if ((rightIndex < maxRange) && (input[rightIndex] > input[smallIndex]))
		smallIndex = rightIndex;

	if (smallIndex != current){
		swap(current, smallIndex);
		heapify(smallIndex, maxRange);
	}

}

void Sort::swap(int index1, int index2){
	int temp;
	temp = input[index1];
	input[index1] = input[index2];
	input[index2] = temp;
}