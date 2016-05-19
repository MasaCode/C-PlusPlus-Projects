#pragma once

using namespace System;

ref class Cell
{
public:
	Cell();
	Cell(int x, int y, char symbol,int index);
	Cell(System::Drawing::Point location, char symbol,int index);
	
	//setter
	void setSymbol(char symbol);

	//getters
	System::Drawing::Point getPoint();
	int getX();
	int getY();
	char getSymbol();
	int getIndex();

private:
		System::Drawing::Point _location;
		char _symbol;
		int _index;

};

