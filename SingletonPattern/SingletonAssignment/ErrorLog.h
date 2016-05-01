#ifndef ERRORLOG_H
#define ERRORLOG_H

#include <string>
using std::string;

class ErrorLog{
public:
	virtual ~ErrorLog();
	static ErrorLog* Instance();

	void WarningLog(string);
	void SevereLog(string);
	void DebuggingLog(string);
private:
	static ErrorLog *_Instance;
	char *fileName;

	void WriteLog(string);

protected:
	ErrorLog();

};


#endif