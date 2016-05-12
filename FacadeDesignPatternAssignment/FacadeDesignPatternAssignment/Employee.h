#pragma once

#include <iostream>

class Employee
{
public:
	virtual int getSalary() = 0;
	virtual std::string getName() = 0;
	virtual std::string getType() = 0;
};

