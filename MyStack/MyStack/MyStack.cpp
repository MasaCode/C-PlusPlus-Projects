#include <iostream>
#include "MyStack.h"

using std::cout;
using std::endl;

MyStack::~MyStack(){
	delete[] pointer;
}

MyStack::MyStack(){
	size = 10;
	length = 0;
	pointer = new int[size];
	for (int i = 0; i < size; i++)
		pointer[i] = -99;
}

MyStack::MyStack(int StackSize){
	size = StackSize > 0 ? StackSize : 10;
	length = 0;
	pointer = new int[size];
	for (int i = 0; i < size; i++)
		pointer[i] = -99;
}

void MyStack::push(int value){
	for (int i = size - 1; i > 0; i--)
		pointer[i] = pointer[i-1];

	pointer[0] = value;
	length++;
}

void MyStack::pop(){
	if (!empty()){
		for (int i = 0; i < size - 1; i++)
			pointer[i] = pointer[i + 1];
		
		pointer[size - 1] = -99;
		length--;
	}
}

int MyStack::top(){
	return pointer[0];
}

bool MyStack::empty(){
	for (int i = 0; i < size; i++){
		if (pointer[i] != -99)
			return false;
	}
	
	return true;
}

int MyStack::Size(){
	return size;
}

int MyStack::Length(){
	return length;
}

bool MyStack::operator!=(const MyStack &right){
	return !(*this == right);
}

bool MyStack::operator==(const MyStack &right){
	if (size != right.size)
		return false;

	for (int i = 0; i < size; i++){
		if (pointer[i] != right.pointer[i])
			return false;
	}

	return true;
}

MyStack& MyStack::operator=(const MyStack &right){
	if (this != &right){
		if (size != right.size){
			delete[] pointer;
			size = right.size;
			pointer = new int[size];
		}
		
		for (int i = 0; i < size; i++)
			pointer[i] = right.pointer[i];
	}

	return *this;
}

//To Debug
void MyStack::Print(){
	for (int i = 0; i < length; i++){
		cout << pointer[i] << " ";
	}
}