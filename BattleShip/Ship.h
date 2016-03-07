#ifndef Ship_h
#define Ship_h
#include <iostream>
#include <string>
#include "Log.h"



#define M 9


using std::istream;
using std::ostream;
using std::string;

class Ship{

public:
	void Place();
	int GetY(); //Get  x , y , placed
	int GetX();
	int GetPlaced();
	void setName(string);
	string getName();
	void setSize(int);
	int getSize();


private:
	string ShipName; // Name of Ship
	int ShipSize; // size of ship
	//int placed;// horizontally("0") or vertically("1")
	int placed; // right('0') or up('1') or left(2') or down('3')
	int x; // x value
	int y; // y value
};


#endif /* Ship_h */
