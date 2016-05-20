#pragma once

#include "Observer.h"
#include "TimeSubject.h"

class CivilianTime : public Observer{
public:
	CivilianTime(TimeSubject* subject);
	~CivilianTime();

	void update() override;
	void showtime() override;

};


class MilitaryTime : public Observer{
public:
	MilitaryTime(TimeSubject* subject);
	~MilitaryTime();

	void update() override;
	void showtime() override;

};


class ZuluTime : public Observer{
public:
	ZuluTime(TimeSubject* subject);
	~ZuluTime();

	void update() override;
	void showtime() override;
};