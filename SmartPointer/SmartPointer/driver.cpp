#include "smart_pointer.h"
#include "Test.h"
#include <string>

void temp(){
	Test *a = new Test("Test");
	smart_pointer<Test> p;
	smart_pointer<Test> w;
	
	std::cout << "Before -> ";
	p.Print();

	p = a;
	w = p;

	std::cout << "After -> ";
	p.Print();

	std::cout << "The function is about to return." << std::endl;
}

void main(){
	
	temp();

	int t;
	std::cin >> t;
	
}