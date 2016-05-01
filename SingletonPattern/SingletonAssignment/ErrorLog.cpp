#include "ErrorLog.h"
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

ErrorLog* ErrorLog::_Instance = 0;

ErrorLog* ErrorLog::Instance(){
	if (_Instance == 0){
		_Instance = new ErrorLog;
	}

	return _Instance;
}


ErrorLog::ErrorLog(){
	fileName = "log.txt";
}

ErrorLog::~ErrorLog(){
	delete fileName;
}

//Util Functions

void ErrorLog::WriteLog(string log){
	FILE *fw = fopen(fileName, "a");
	if (fw == NULL){
		cout << "I can not open the file...." << endl;
		return;
	}

	fprintf(fw,"%s\n" ,log.c_str());
}

void ErrorLog::SevereLog(string error){
	WriteLog("Error : " + error);
}

void ErrorLog::WarningLog(string warning){
	WriteLog("Warning : " + warning);
}

void ErrorLog::DebuggingLog(string info){
	WriteLog("Debugging : " + info);
}