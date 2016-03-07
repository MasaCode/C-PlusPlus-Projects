#ifndef GameLog_h
#define GameLog_h
#include <iostream>
#include <string>
#include <vector>
#include "Log.h"

using std::istream;
using std::ostream;
using std::string;
using std::vector;

typedef struct infomation{
	int score;
	char name[30];
}info;


class GameLog : public Log{
private:
	//vector <int> score;
	//vector <char *> name;
	//int score[100];
	//char name[100][30];

	info playerinfo[150]; // structure for sort.

	int count;
	//char *FileName;
public:
	//void SetLogFileName(char *);
	//void setVector();
	int Read();
	void Write();
	void Add(int, char *);
	void Show();

};


#endif /* GameLog_h */
