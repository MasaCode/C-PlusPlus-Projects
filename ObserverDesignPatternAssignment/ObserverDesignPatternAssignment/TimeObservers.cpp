#include "TimeObservers.h"

#include <string>
#include <iostream>
////////////////////////////////////////// Civilian Time Observer //////////////////////////////////////////

CivilianTime::CivilianTime(TimeSubject* subject) : Observer(subject)
{
	//Empty
}

CivilianTime::~CivilianTime()
{
	//Empty
}

void CivilianTime::update(){

	showtime();

}

void CivilianTime::showtime(){
	int hour = getSubject()->getHour();
	auto timeState = getSubject()->getTimeState();
	if (timeState == Time_State::NONE){
		timeState = hour >= 12 ? Time_State::PM : Time_State::AM;
	}
	if (timeState == Time_State::PM && hour != 12){
		hour -= 12;
	}

	std::string time = timeState == Time_State::AM ? "am" : "pm";
	std::cout << "Civilian Time : " << hour << " : " << getSubject()->getMinute() << " : " << getSubject()->getSecond() << " , " << time << std::endl;
}

////////////////////////////////////////// Military Time Observer //////////////////////////////////////////

MilitaryTime::MilitaryTime(TimeSubject* subject) : Observer(subject)
{
	//Empty
}

MilitaryTime::~MilitaryTime()
{
	//Empty
}


void MilitaryTime::update(){
	
	showtime();
}


void MilitaryTime::showtime(){
	int hour = getSubject()->getHour();
	if (getSubject()->getTimeState() == Time_State::PM){
		hour += 12;
	}
	std::cout << "Military Time : " << hour << " : " << getSubject()->getMinute() << " : " << getSubject()->getSecond() << std::endl;
}


////////////////////////////////////////// Zulu Time Observer //////////////////////////////////////////

ZuluTime::ZuluTime(TimeSubject* subject) : Observer(subject)
{
	//Empty
}

ZuluTime::~ZuluTime()
{
	//Empty
}

void ZuluTime::update(){

	showtime();
}

void ZuluTime::showtime(){
	std::string area;
	int hour = getSubject()->getHour();
	if (getSubject()->getTimeState() == Time_State::PM){
		hour += 12;
	}

	switch (getSubject()->getZone()){
	case 0:
		area = "GMT"; break;
	case 1:
		area = "UTC"; break;
	case 2:
		area = "ECT"; break;
	case 3:
		area = "EET"; break;
	case 4:
		area = "ART"; break;
	case 5:
		area = "EAT"; break;
	case 6:
		area = "MET"; break;
	case 7:
		area = "NET";  break;
	case 8:
		area = "PLT";  break;
	case 9:
		area = "IST";  break;
	case 10:
		area = "BST";  break;
	case 11:
		area = "VST";  break;
	case 12:
		area = "CTT";  break;
	case 13:
		area = "JST";  break;
	case 14:
		area = "ACT";  break;
	case 15:
		area = "AET";  break;
	case 16://
		area = "SST";  break;
	case 17:
		area = "NST";  break;
	case 18:
		area = "MIT";  break;
	case 19:
		area = "HST";  break;
	case 20:
		area = "AST";  break;
	case 21://
		area = "PST";  break;
	case 22:
		area = "PNT";  break;
	case 23:
		area = "MST";  break;
	case 24:
		area = "CST";  break;
	case 25:
		area = "EST";  break;
	case 26:
		area = "IET";  break;
	case 27:
		area = "PRT";  break;
	case 28://
		area = "CNT";  break;
	case 29:
		area = "AGT";  break;
	case 30:
		area = "BET";  break;
	case 31:
		area = "CAT";  break;
	default:
		std::cout << "I dont know what you are inputting." << std::endl;
	}
	std::cout << "Zulu Time     : " << hour << " : " << getSubject()->getMinute() << " : " << getSubject()->getSecond() << " , " << area << std::endl;
}