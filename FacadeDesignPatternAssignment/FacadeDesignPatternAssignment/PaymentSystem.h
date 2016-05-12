#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Employee.h"
#include "Boss.h"
#include "CommissionWorker.h"
#include "HourlyWorker.h"
#include "PaymentSystem.h"
#include "PieceWorker.h"

using std::cin;
using std::cout;
using std::endl;

class PaymentSystem
{
public:
	PaymentSystem();
	~PaymentSystem();

	void run();

private:
	int menu();
	void Print();
	void AddBoss();
	void AddCommissionWorker();
	void AddPieceWorker();
	void AddHourlyWorker();


private:
	std::vector<Employee*> _employees;
};

