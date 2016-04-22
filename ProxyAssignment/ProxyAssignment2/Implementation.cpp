#include <iostream>
#include <stdio.h>
#include <exception>
#include "Implementation.h"

using std::cout;
using std::endl;

Implementation::Implementation(){
	ReadData();
}


void Implementation::ReadData(){
	char *fileName = "test.txt";
	FILE *fr = fopen(fileName, "r");
	int tempid,tempbalance,templimit;
	char *name, *tempaccountNum;
	idMap::iterator iditr;

	int count = 0; //debug

	if (fr == NULL)
		cout << "I cannot open the file....." << endl;

	while (!std::feof(fr)){
		name = new char[20];
		tempaccountNum = new char[20];
		std::fscanf(fr, "%d %s %d %d %s \n", &tempid, name, &tempbalance, &templimit, tempaccountNum);
		//fprintf(stdout, "%d %s %d %d %s \n", tempid, name, tempbalance, templimit, tempaccountNum);
			id.insert(idMap::value_type(tempid, name));
			balance.push_back(tempbalance);
			limit.push_back(templimit);
			accountNumber.push_back(tempaccountNum);
		delete[] name, tempaccountNum;
	}

	fclose(fr);
}



int Implementation::GetBalance(int _id){
	return balance[_id];
}

int Implementation::GetLimit(int _id){
	return limit[_id];
}

std::string Implementation::GetaccountNumber(int _id){
	return accountNumber[_id];
}


int Implementation::Namecheck(std::string name){
	idMap::iterator itr;
	for (itr = id.begin(); itr != id.end(); itr++){
		if (itr->second == name){
			return itr->first;
		}
	}

	return -1;
}