#ifndef Log_h
#define Log_h
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Log{
public:

	//virtual void SetLogFileName(char *) = 0;
	virtual void WriteInFile(char *){}

};


#endif /* Log_h */
