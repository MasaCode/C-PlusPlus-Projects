#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Ship.h"

using std::istream;
using std::ostream;
using std::string;


int Ship::GetY(){
	return y;
}

int Ship::GetX(){
	return x;
}

int Ship::GetPlaced(){
	return placed;
}


void Ship::setName(string Ship){
	ShipName = Ship;
}

string Ship::getName(){
	return ShipName;
}

void Ship::setSize(int size){
	ShipSize = size;
}

int Ship::getSize(){
	return ShipSize;
}


void Ship::Place(){
	srand((unsigned)time(0));
	int i, difplaced, difposition, rplaced = 0, rx = 0, ry = 0;
	difposition = ((M - 2) - 0) + 1;
	difplaced = (3 - 0) + 1;
	for (i = 0; i<10; i++){
		//difplaced = (1-0) + 1;
		rplaced = (rand() % difplaced) + 0;
		rx = (rand() % difposition) + 0;
		ry = (rand() % difposition) + 0;
	}
	placed = rplaced;
	x = rx;
	y = ry;

}

