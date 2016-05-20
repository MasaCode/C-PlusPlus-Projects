#pragma once

#include <vector>



class Observer;

//Civilian time is 1 to 12
//Military time is 1 to 24
//Zulu need the time zone to recoginize area

using namespace std;
enum class Time_State{
	AM = 0,
	PM = 1,
	NONE = 3
};

class TimeSubject
{
public:
	TimeSubject();
	~TimeSubject();
	void registerObserver(Observer* observer){ _views.push_back(observer); }
	void removeObserver(Observer* observer);
	void notify();
	
	void SetTime(int hour, int minute, int second,int zone,int timeState = 3);
	//void SetTime(int hour, int minute, int second);
	int getHour() { return _hour; }
	int getMinute(){ return _minute; }
	int getSecond(){ return _second; }
	int getZone(){ return _zone; }
	Time_State getTimeState(){ return _timeState; }

private:
	int _hour = 0;
	int _minute = 0;
	int _second = 0;
	int _zone = 0;
	Time_State _timeState;
	 std::vector<Observer*> _views;

};

