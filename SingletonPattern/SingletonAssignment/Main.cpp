#include "ErrorLog.h"

void main(){
	ErrorLog *log = ErrorLog::Instance();

	log->DebuggingLog("I am creating a singleton class.");
	log->SevereLog("Wrong Password.....");
	log->WarningLog("The variable is never used.");

}