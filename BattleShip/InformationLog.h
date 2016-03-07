#ifndef InformationLog_h
#define InformationLog_h
#include <iostream>
#include <string>
#include "Log.h"

using std::istream;
using std::ostream;
using std::string;


class InformationLog : public Log{
private:
	//char *FileName;

public:
	//void SetLogFileName(char *);
	void WriteInFile(char *);
	void SWriteInFile(char *, int, char *, int, char *);
};


#endif /* InformationLog_h */
