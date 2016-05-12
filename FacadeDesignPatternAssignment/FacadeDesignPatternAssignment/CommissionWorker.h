#pragma once

#include "Employee.h"
#include <iostream>

class CommissionWorker : public Employee
{
public:
	CommissionWorker(int wage, int salary, std::string name) : _wage(wage), _salary(salary), _name(name)
	{
	}
	~CommissionWorker(){}

	int getSalary(){ return (_wage + _salary*0.03); }
	std::string getName(){ return _name; }
	std::string getType(){ return "Commission Worker"; }

private:

	int _wage;
	int _salary;
	std::string _name;
};