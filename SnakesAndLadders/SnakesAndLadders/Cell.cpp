#include "Cell.h"


Cell::Cell()
{
	//Empty
}

Cell::Cell(int x, int y, char symbol, int index) : _location(x, y), _symbol(symbol), _index(index)
{
	//Empty
}

Cell::Cell(System::Drawing::Point location, char symbol, int index) : _location(location), _symbol(symbol), _index(index)
{
	//Empty
}

void Cell::setSymbol(char symbol){
	_symbol = symbol;
}

System::Drawing::Point Cell::getPoint(){
	return _location;
}

char Cell::getSymbol(){
	return _symbol;
}

int Cell::getIndex(){
	return _index;
}

int Cell::getX(){
	return _location.X;
}

int Cell::getY(){
	return _location.Y;
}
