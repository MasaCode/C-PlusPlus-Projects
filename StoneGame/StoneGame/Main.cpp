#include <iostream>
#include "StoneGame.h"

using std::cout;
using std::cin;
using std::endl;

bool UserInput(int Input[]){
	cout << "Plase Enter Where you want to move the stone." << endl;
	cout << "Location of the stone : " << endl;
	cout << "Row : ";
	cin >> Input[0];
	cout << "Column : ";
	cin >> Input[1];

	cout << "Location of where you want to move the stone to." << endl;
	cout << "Row : ";
	cin >> Input[2];
	cout << "Colmun : ";
	cin >> Input[3];

	if (Input[0] > 16 || Input[1] > 16 || Input[2] > 16 || Input[3] > 16) return false;

	return true;
}

void main(){
	int Input[4]; 
	// [0] : Row of the stone, [1] : Column of the stone, [2] : Row of where the user want to move it to, [3] : Column of where the user want to move it to.
	StoneGame stones = StoneGame();
	bool isValidInput, isPossibleToMove, isContinue;
	int Score = 0;

	stones.CreateStones(10);
	stones.Print();
	do{
		isValidInput = UserInput(Input);
		if (!isValidInput)
			cout << "Plase Enter Again..." << endl;
		else{
			isPossibleToMove = stones.Move(Input[0], Input[1], Input[2], Input[3]);
			if (!isPossibleToMove)
				cout << "It's impossible to move it." << endl;
			else
				cout << "The stone moved!!!" << endl;
		}
		stones.Print();
		isContinue = stones.IsContinue();
	} while (isContinue);

	Score = stones.CountScore();
	cout << endl << "You cannnot move no more......" << endl;
	cout << "Your could not remove " << Score  << " stones" << endl;

}