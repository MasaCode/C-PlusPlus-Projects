#pragma once

#include "Employee.h"
#include <iostream>

class PieceWorker : public Employee
{
public:
	PieceWorker(int pieces, int price, std::string name) : _pieces(pieces), _price(price),_name(name){}
	~PieceWorker(){}

	int getSalary(){ return (_pieces*_price); }
	std::string getName(){ return _name; }
	std::string getType(){ return "Piece Worker"; }

private:
	int _pieces;
	int _price;
	std::string _name;
};