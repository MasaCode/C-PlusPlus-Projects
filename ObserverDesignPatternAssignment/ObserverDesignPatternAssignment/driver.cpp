#include "TimeObservers.h"
#include "TimeSubject.h"

#include <iostream>

void main(){
	TimeSubject sbj;
	CivilianTime civ(&sbj);
	MilitaryTime mil(&sbj);
	ZuluTime zul(&sbj);

	sbj.SetTime(23, 43, 44, 23);
	sbj.SetTime(11, 33, 55, 11, 0);

	int t = 0;
	std::cout << "Press any key to quit....";
	std::cin >> t;

}