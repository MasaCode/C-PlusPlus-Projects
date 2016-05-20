#pragma once
#include "TimeSubject.h"


class Observer
{
public:
	//Observer(){}
	Observer(TimeSubject* subject){
		_subject = subject;
		subject->registerObserver(this);
	}

	virtual void update() = 0;
	virtual void showtime() = 0;
protected:
	TimeSubject* getSubject(){ return _subject; }
private:
	TimeSubject* _subject;
};

