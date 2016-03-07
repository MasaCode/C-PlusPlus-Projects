#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "GameLog.h"

using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
/*
void GameLog::SetLogFileName(char *FileName){
	this->FileName = FileName;
}

void GameLog :: setVector(){
score.resize(100);
name.resize(100);
}
*/

int GameLog::Read(){
	FILE *fp;
	int i = 0;
	int tscore;
	char tname[20];


	if ((fp = fopen("result.txt", "r")) == 0){ //for Xcode
		//if((fp = fopen(FileName,"a")) == 0){
		cout << "I cannot read the data from file" << endl;
	}
	else{
		do{
			if ((feof(fp)) != 0){
				break;
			}
			fscanf(fp, "%d %s\n", &tscore, tname);
			playerinfo[i].score = tscore;
			strcpy(playerinfo[i].name, tname);
			i++;
			memset(tname, '\0', sizeof(tname));
		} while (true);
	}
	count = i;

	cout << "Here is read function and count is " << count << endl;
	fclose(fp);
	return count;
}



void GameLog::Write(){
	FILE *fp;



	if ((fp = fopen("result.txt", "w")) == 0){ //for Xcode
		//if((fp = fopen(FileName,"a")) == 0){
		cout << "I cannot save the data to file" << endl;
	}
	else{
		for (int i = 0; i<count; i++){
			fprintf(fp, "%d %s\n", playerinfo[i].score, playerinfo[i].name);
		}
	}
	fclose(fp);
}

/*
void GameLog :: Add(int score1,char *player){
int tempscore;
char *tempname;
score[count] = score1;
strcpy(name[count],player);
count++;
for(int i=0; i<count-1; i++){
for(int j=0; j<count; j++){
if(score[j] > score[j+1]){
tempscore = score[j];
//strcpy(tempname,name[j]);
tempname = name[j];
//memset(name[j],'\0',sizeof(name[j]));
score[j] = score[j+1];
strcpy(name[j],name[j+1]);
//memset(name[j+1],'\0',sizeof(name[j+1]));
score[j+1] = tempscore;
strcpy(name[j+1],tempname);
//tempname = 0;
}
}
}

cout << "Here is the Add function" << endl;
for(int masashi = 0; masashi<=count; masashi++){
cout << "score" <<masashi << " : " << score[masashi] << " name : " << name[masashi] << endl;
}

}
*/




void GameLog::Add(int pscore, char *player){
	info temp;
	playerinfo[count].score = pscore;
	strcpy(playerinfo[count].name, player);
	count++;
	int i = 0, j = 0, min = 0, place = 0;

	for (i = 0; i<count - 1; i++){
		min = playerinfo[i].score;
		for (j = i; j<count; j++){
			if (min > playerinfo[j].score){
				min = playerinfo[j].score;
				place = j;
			}
		}
		memcpy(&temp, &playerinfo[i], sizeof(temp));
		memcpy(&playerinfo[i], &playerinfo[place], sizeof(playerinfo[place]));
		memcpy(&playerinfo[place], &temp, sizeof(temp));

	}

}

void GameLog::Show(){
	int i = 0;
	for (i = 0; i<count; i++){
		cout /*<< setw(20) */ << i + 1 << " : " << playerinfo[i].score << "   " << playerinfo[i].name << endl;
	}

	cout << endl << endl;
}




