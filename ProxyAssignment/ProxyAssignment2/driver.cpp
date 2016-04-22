#include <iostream>
#include "Interfaceh.h"

using std::cin;

std::string InputName(){
	std::string name;
	cout << "Please enter the client name : ";
	cin >> name;
	return name;
}


void main(){
	Interface test;
	std::string name;
	name = InputName();
	if (test.check(name)){
		test.Print();
	}


}