#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
using std::ostream;

class MyStack{
private:
	int size;
	int *pointer;
	int length;

public:
	MyStack();
	MyStack(int);
	~MyStack();

	void push(int);
	void pop();
	int top();
	bool empty();
	int Size();
	int Length();
	
	//To Debug
	void Print();

	MyStack & operator =(const MyStack &);
	bool operator ==(const MyStack &);
	bool operator !=(const MyStack &);
};


#endif