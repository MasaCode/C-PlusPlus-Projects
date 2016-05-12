#pragma once

#include "Employee.h"
#include <iostream>

class HourlyWorker : public Employee
{
public:

	HourlyWorker(int workinghour, int price, int standardhour, std::string name) :_workinghour(workinghour), _price(price), _standardhour(standardhour), _name(name)
	{
	}

	~HourlyWorker(){}
	
	int getSalary(){
		int overSalaryhour;
		overSalaryhour = _workinghour > _standardhour ? (_workinghour - _standardhour) : 0;
		_workinghour -= overSalaryhour;
		return (overSalaryhour*(_price *1.5)) + _workinghour * _price;
	}

	std::string getName(){ return _name; }
	std::string getType(){ return "Hourly Worker"; }

private:
	int _workinghour;
	int _price;
	int _standardhour;
	std::string _name;
};