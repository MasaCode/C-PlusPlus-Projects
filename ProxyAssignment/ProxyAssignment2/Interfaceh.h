#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include "Implementation.h"

using std::cout;
using std::endl;

class Interface{
private:
	Implementation *ptr;
	int id;

public:
	Interface(){ ptr = new Implementation(); }
	~Interface(){ delete ptr;}
	bool check(std::string name);
	void Print();

};


bool Interface::check(std::string name){
	id = ptr->Namecheck(name);
	if (id == -1){
		return false;
	}
	return true;
}

void Interface::Print(){
	cout << "ID : " << id+1 << endl;
	cout << "Balance : " << ptr->GetBalance(id) << endl;
	cout << "Limit : " << ptr->GetLimit(id) << endl;
	cout << "Account Number : " << ptr->GetaccountNumber(id) << endl;
}


#endif