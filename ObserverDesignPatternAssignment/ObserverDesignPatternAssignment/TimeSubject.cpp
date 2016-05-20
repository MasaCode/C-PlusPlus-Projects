#include "TimeSubject.h"
#include "Observer.h"

TimeSubject::TimeSubject()
{
}


TimeSubject::~TimeSubject()
{
}

void TimeSubject::removeObserver(Observer* observer){
	for (unsigned int i = 0; i < _views.size(); i++){
		if (_views[i] == observer){
			delete _views[i];
			_views[i] = _views.back();
			_views.pop_back();
		}
	}
}

void TimeSubject::notify(){
	for (unsigned int i = 0; i < _views.size(); i++){
		_views[i]->update();
	}
}

/*
void TimeSubject::SetTime(int hour, int minute, int second){
	_hour = hour;
	_minute = minute;
	_second = second;
}
*/

void TimeSubject::SetTime(int hour, int minute, int second,int zone,int timeState){
	_hour = hour;
	_minute = minute;
	_second = second;
	_zone = zone;

	switch (timeState){
		case 0:
			_timeState = Time_State::AM;
			break;
		case 1:
			_timeState = Time_State::PM;
			break;
		default:
			_timeState = Time_State::NONE;
			break;
	}

	notify();
}

