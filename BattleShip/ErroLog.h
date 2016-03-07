#ifndef ErroLog_h
#define ErroLog_h
#include <iostream>
#include <string>
#include "Log.h"

using std::istream;
using std::ostream;
using std::string;


class ErroLog : public Log{
private:
	//char *FileName;

public:
	//void SetLogFileName(char *);
	void WriteInFile(char *);
};


#endif /* ErroLog_h */
