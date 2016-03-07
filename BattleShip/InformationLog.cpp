#include <iostream>
#include <string>
#include <sstream>
#include "InformationLog.h"
#include <stdio.h>
#include <stdlib.h>

using std::istream;
using std::ostream;
using std::string;
/*
void InformationLog::SetLogFileName(char  *FileName){
	this->FileName = FileName;
}
*/
void InformationLog::WriteInFile(char *text){
	FILE *fp;


	fp = fopen("Info.txt", "a");
	if (fp == 0){
		std::cout << "I cannot read the file" << std::endl;
	}
	else{
		fprintf(fp, "%s\n", text);
	}
	fclose(fp);
}


void InformationLog::SWriteInFile(char *text1, int x, char *text2, int y, char *text3){
	FILE *fp;

	fp = fopen("Info.txt", "a");
	if (fp == 0){
		std::cout << "I cannot read the file" << std::endl;
	}
	else{
		fprintf(fp, "%s%d%s%d%s\n", text1, x, text2, y, text3);
	}
	fclose(fp);
}


