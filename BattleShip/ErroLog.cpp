#include <iostream>
#include <string>
#include "ErroLog.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using std::istream;
using std::ostream;
using std::string;
/*
void ErroLog::SetLogFileName(char  *FileName){
	this->FileName = FileName;
}
*/
void ErroLog::WriteInFile(char *text){
	FILE *fp;

	fp = fopen("Erro.txt", "a");

	if (fp == 0){
		std::cout << "I cannot read the file" << std::endl;
	}
	else{
		fprintf(fp, "%s\n", text);
	}

	fclose(fp);
}