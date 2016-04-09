#include <iostream>
#include "StoneGame.h"

using std::cout;
using std::endl;

StoneGame::StoneGame(){
	for (int i = 0; i < 256; i++)
		GameGrid[i] = 'E';
}

void StoneGame::CreateStones(int NumberOfStones){
	int i,place,next;
	bool isValid;
	for (i = 0; i < (NumberOfStones/2); i++){
		place = rand() % 256;
		next = rand() % 4; 
		// if next is 0 : right (place + 1) , if next is 1 : left (place - 1) , if next is 2 : above (place - 16) , if next is 3 : below (place + 16) 
		isValid = CheckPlacement(place, next);
		if (isValid){
			GameGrid[place] = 'S';
			GameGrid[NextPlace] = 'S';
		}
		else
			i--;
	}

}



bool StoneGame::CheckPlacement(int place, int next){
	if (GameGrid[place] == 'S') return false; // Cannot place the stones at same place
	
	if (place == 255 && next == 0) return false; // Cannot place it out of Grid.
	if (place == 0 && next == 1) return false; // Cannot place it out of Grid.
	if (place < 16 && next == 2) return false; // Cannot place the stone abobe.
	if (place > 239 && next == 3) return false; // Cannot place the stone below.

	if (next == 0 && ((((place / 16) + 1) * 16 - 1) + 1) < place + 1) return false; // Cannot place the right.
	if (next == 1 && ((place - (place % 16)) - 1) > place - 1) return false; // Cannot place the right;

	switch (next){
	case 0 : 
		NextPlace = place + 1; //right
		break;
	case 1 :
		NextPlace = place - 1; //left
		break;
	case 2 :
		NextPlace = place - 16; //above
		break;
	case 3 :
		NextPlace = place + 16; //below
		break;
	default:
		return false;
	}

	if (GameGrid[NextPlace] == 'S') return false; // Cannot place the stones at same place

	return true;
}


void StoneGame::Print(){
	int i;
	 
	cout << "    1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 " << endl << " 1  ";
	for (i = 0; i < 256; i++){
		if (GameGrid[i] == 'E')
			cout << "*  ";
		if (GameGrid[i] == 'S')
			cout << "X  ";

		if ((i + 1) % 16 == 0 && i != 255){
			cout << endl << " " << ((i + 1) / 16) + 1 << " ";
			if ((i + 1) / 16 < 9)
				cout << " ";
		}
	}

	cout << endl;
}

bool StoneGame::Move(int RowOfFrom, int ColumnOfFrom, int RowOfTo, int ColumnOfTo){
	int movingFrom, movingTo;
	int difference,middle;

	//Calculating the location of the stone.
	if (RowOfFrom == 1)
		movingFrom = ColumnOfFrom - 1;
	else
		movingFrom = (RowOfFrom - 1) * 16 + ColumnOfFrom - 1;

	//Calculating the location of where the user want to move it to.
	if (RowOfTo == 1)
		movingTo = ColumnOfTo - 1;
	else
		movingTo = (RowOfTo - 1) * 16 + ColumnOfTo - 1;

	//until here.

	difference = movingTo - movingFrom; // Calculating the difference of two location
	middle = difference / 2;
	if (!(difference == -32 || difference == 32 || difference == 2 || difference == -2)) return false;

	if (!(GameGrid[movingTo] == 'E' && GameGrid[movingFrom + middle] == 'S')) return false;

	GameGrid[movingFrom] = 'E';
	GameGrid[movingFrom + middle] = 'E';
	GameGrid[movingTo] = 'S';

	return true;
}

bool StoneGame::IsContinue(){
	int i;
	for (i = 0; i < 256; i++){
		if (GameGrid[i] == 'S'){
			if (i > 15 && i < 240){
				if (GameGrid[i + 16] == 'S' || GameGrid[i - 16] == 'S') return true;
			}

			if (GameGrid[i + 1] == 'S' || GameGrid[i - 1] == 'S') return true;
		}
	}

	return false;
}

int StoneGame::CountScore(){
	int Count = 0,i;
	for (i = 0; i < 256; i++){
		if (GameGrid[i] == 'S')
			Count++;
	}

	return Count;
}