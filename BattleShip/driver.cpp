#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>


#include "InformationLog.h"
#include "ErroLog.h"
#include "Ship.h"
#include "GameLog.h"




using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::vector;


char Display[M + 1][M + 1];



void ClearScreen()
{
	std::cout << string(30, '\n');
}


void setCharacter(){
	int i = 0, j = 0;
	for (i = 0; i<M; i++){
		for (j = 0; j<M; j++){
			Display[i][j] = '*';
		}
		Display[i][10] = '\0';
	}

}



void DisplayView(){
	int i = 0, j = 0;

	//cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
	for (int z = 0; z < M; z++){
		if (z == 0){
			cout << setw(2) << " ";
		}
		cout << setw(2) << z + 1;
	}
	cout << endl;
	for (i = 0; i<M; i++){
		cout << setw(2) << i + 1;
		for (j = 0; j<M; j++){
			cout << setw(2) << Display[i][j];
		}
		cout << endl;

		//cout << setw(20) << Display[i] << endl;
	}

	cout << endl;
}

/*
//for testing
void DisplayView(int Field[][M]){
	int i = 0, j = 0;

	//cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
	for (int z = 0; z < M; z++){
		if (z == 0){
			cout << setw(2) << " ";
		}
		cout << setw(2) << z + 1;
	}
	cout << endl;
	for (i = 0; i<M; i++){
		cout << setw(2) << i + 1;
		for (j = 0; j<M; j++){
			cout << setw(2) << Field[i][j];
		}
		cout << endl;

		//cout << setw(20) << Display[i] << endl;
	}

	cout << endl;
}
*/

void setPlace(int size, int Field[][M], int x, int y, int placed){
	int i = 0;
	for (i = 0; i <= size; i++){
		if (placed == 0){
				Field[y][x + i] = 1;
		}
		else if (placed == 1){
				Field[y + i][x] = 1;
		}
		else if (placed == 2){
				Field[y][x - i] = 1;
		}
		else{
				Field[y - i][x] = 1;
		}
	}

}

bool placecheck(int size, int x, int y, int placed,int Field[][M]){
	int i = 0;
	for (i = 0; i <= size; i++){
		if (placed == 0){
			if (Field[y][x + i] == 1){
				return false;
			}
			else if ((x + i) > M - 1){
				return false;
			}
		}
		else if (placed == 1){
			if (Field[y + i][x] == 1){
				return false;
			}
			else if ((y + i) > M - 1){
				return false;
			}
		}
		else if (placed == 2){
			if (Field[y][x - i] == 1){
				return false;
			}
			else if ((x - i) < 0){
				return false;
			}
		}
		else{
			if (Field[y - i][x] == 1){
				return false;
			}
			else if ((y - i) < 0){
				return false;
			}
		}
	}
	return true;

}

void createShip(Ship ships[], int Field[][M], InformationLog info, ErroLog erro){
	int i = 0, x, y, placed;
	bool flag=false,check=false;
	char *erromessage = new char[50], *infomessage = new char[50];
	std::ostringstream os;
	string name;
	cout << "Now Creating the ship....." << endl;
	while (true){
		
			ships[i].setSize(i);

			ships[i].Place();
			x = ships[i].GetX();
				y = ships[i].GetY();
				placed = ships[i].GetPlaced();
			check = placecheck(i, x, y, placed, Field);
			
			while (check == false){
				strcpy(erromessage, "Cannot create the ship successfully");
				erro.WriteInFile(erromessage);

				ships[i].Place();
				x = ships[i].GetX();
				y = ships[i].GetY();
				placed = ships[i].GetPlaced();
				check = placecheck(i, x, y, placed,Field);
			}

			os << "Ship" << i;
			name = os.str();
			ships[i].setName(name);
			os.clear();

			setPlace(i, Field, x, y, placed);

			//cout << " y = " << y + 1 << " x = " << x + 1 << " size = " << i + 1 << " placed = " << placed << endl;
			strcpy(infomessage, "Create the ship successfully");
			info.WriteInFile(infomessage);
			i++;

		
		if (i == 3){
			break;
		}
	}

	delete[] erromessage;
	delete[] infomessage;

}


int play(Ship ships[], int Field[][M], InformationLog info, ErroLog erro, char *player){
	int score = 1;
	int x, y;
	int flag = 6; // number of "1" that user need to shot.
	string message;
	std::ostringstream os;
	char *htext1 = new char[50], *htext2 = new char[50], *htext3 = new char[50];
	char *mtext1 = new char[50], *mtext2 = new char[50], *mtext3 = new char[50];

	do{
		cout << endl;
		//ClearScreen();
		DisplayView();
		//DisplayView(Field); // for testing
		cout << endl;


		cout << endl << "Where do you wanna hit?" << endl;
		do{
			cout << "y (1 to 10) : ";
			cin >> y;
			cout << "x (1 to 10) : ";
			cin >> x;
			if (x>0 && x<M + 1 && y>0 && y<M + 1){
				break;
			}
			else{
				cout << "Plase enter again " << endl;
			}
		} while (true);
		cout << "Shoot to (" << y << " , " << x << ")" << endl;
		score++;
		x = x - 1;
		y = y - 1;
		if (Field[y][x] == 1){
			cout << setw(15) << " HIT!!!!!!!!! " << endl;
			Display[y][x] = 'H';
			strcpy(htext1, "Hit to (");
			strcpy(htext2, " , ");
			strcpy(htext3, " ) ");
			info.SWriteInFile(htext1, x, htext2, y, htext3);
			Field[y][x] = 0;

			//os << "HIT to (" << x << " , " << y << ")";
			//message = os.str();
			//int len = sizeof(message);
			//memcpy(text,message.c_str(),len+1);
			//info.WriteInFile(text);
			//os.clear();
			//message.clear();
			//memset(text,'\0',len+1);

			flag--;
		}
		else{
			cout << setw(15) << " MISS....... " << endl;
			if (Display[y][x] == '*'){
				Display[y][x] = 'M';
			}
			strcpy(mtext1, "Miss to (");
			strcpy(mtext2, " , ");
			strcpy(mtext3, " ) ");
			info.SWriteInFile(mtext1, x, mtext2, y, mtext3);


			//os << "Miss to (" << x << " , " << y << ")";
			//message = os.str();
			//int len = sizeof(message);
			//memcpy(text,message.c_str(),len+1);
			//info.WriteInFile(text);
			//os.clear();
			//message.clear();
			//memset(text,'\0',len+1);

		}


	} while (flag > 0);

	score = score - 1;
	

	cout << setw(20) << "You destroyed all ships" << endl;
	cout << setw(20) << " Your score is " << score << endl << endl;

	delete[] htext1;
	delete[] htext2;
	delete[] htext3;
	delete[] mtext1;
	delete[] mtext2;
	delete[] mtext3;
	
	return score;
}


int Menu(){
	int choice;
	cout << setw(15) << "Menu" << endl;
	cout << setw(15) << "1 . Play Game " << endl;
	cout << setw(15) << " 2 . See the Mark " << endl;
	cout << setw(15) << " 3 . End the Game " << endl << endl << endl;
	cout << "your choice : ";
	cin >> choice;
	return choice;
}


int main(){
	InformationLog info;
	ErroLog erro;
	Ship ships[3];
	GameLog game;
	//game.setVector();
	game.Read();
	int choice, score;
	int Field[M][M] = { 0 };

	//for windows
	/*
	cout << setw(30) << "Settomg the file name" << endl<<endl;
	cout << "For Erro message : ";
	char *errof;
	cin >> errof;
	erro.SetLogFileName(errof);

	cout << "For information" << endl;
	char *infof;
	cin >> infof;
	info.SetLogFileName(infof);

	cout << "For Game Log";
	char *gameL;
	cin >> gameL;
	game.SetLogFileName(gameL);
	*/

	do{
		choice = Menu();
		setCharacter();
		if (choice == 1){
			char *player = new char[30];
			createShip(ships, Field, info, erro);
			cout << endl << "Plase enter your name : ";
			cin >> player;
			score = play(ships, Field, info, erro, player);
			game.Add(score, player);
			delete[] player;
		}
		else if (choice == 2){
			game.Show();
		}
		else{
			game.Write();
			break;
		}

	} while (true);



	return 0;
}



