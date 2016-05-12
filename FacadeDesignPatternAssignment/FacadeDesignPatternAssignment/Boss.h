#pragma once

#include "Employee.h"
#include <iostream>

class Boss : public Employee
{
public:
	Boss(int salary,std::string name) : _salary(salary),_name(name){}
	~Boss(){}

	int getSalary(){ return _salary; }
	std::string getName(){ return _name; }
	std::string getType(){ return "Boss"; }
private:
	int _salary;
	std::string _name;
};

