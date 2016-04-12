#include <iostream>
#include "MyStack.h"

using std::cout;
using std::cin;
using std::endl;

void main(){
	MyStack stack(20);
	
	if (stack.empty())
		cout << "Stack is empty.." << endl;

	stack.push(4);
	stack.push(2);
	stack.push(3);


	cout << "The length of stack is " << stack.Length() << endl;

	cout << "The Elements of Stack are ";
	while (!stack.empty()){
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	if (stack.empty())
		cout << "Stack is empty.." << endl;


}