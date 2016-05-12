#include "PaymentSystem.h"


PaymentSystem::PaymentSystem()
{
}


PaymentSystem::~PaymentSystem()
{

	for (int i = 0; i < _employees.size(); i++)
		delete _employees[i];
}


void PaymentSystem::run(){
	int menuInput;
	while (true){
		menuInput = menu();
		switch (menuInput){
		case 1:
			AddBoss();
			break;
		case 2:
			AddPieceWorker();
			break;
		case 3:
			AddCommissionWorker();
			break;
		case 4:
			AddHourlyWorker();
			break;
		case 5:
			Print();
			break;
		case 6:
			return;
		default :
			break;
		}
	}
}


int PaymentSystem::menu(){
	int input;
	cout << "\tMenu\t" << endl;
	cout << "1. Input Boss's salary" << endl;
	cout << "2. Piece Worker's salary" << endl;
	cout << "3. Commission Worker's salary" << endl;
	cout << "4. Hourly Worker's salary" << endl;
	cout << "5. Print out the information" << endl;
	cout << "6. Exit" << endl;
	cout << "Your input -> ";
	cin >> input;
	return input;
}

void PaymentSystem::AddBoss(){
	int salary;
	std::string name;
	cout << endl << "	Bos Payment  " << endl;
	cout << "What is the name? -> ";
	cin >> name;
	cout << "How much is the salary? -> ";
	cin >> salary;
	_employees.emplace_back(new Boss(salary,name));
}

void PaymentSystem::AddCommissionWorker(){
	int salary,wage;
	std::string name;
	cout << endl << "	CommissionWorker Payment" << endl;
	cout << "What is the name? -> ";
	cin >> name;
	cout << "How much is the salary? -> ";
	cin >> salary;
	cout << "How much is the wage? -> ";
	cin >> wage;
	_employees.emplace_back(new CommissionWorker(wage, salary, name));
}

void PaymentSystem::AddPieceWorker(){
	int price,pieces;
	std::string name;
	cout << "What is the name? -> ";
	cin >> name;
	cout << "How much is the price per piece? -> ";
	cin >> price;
	cout << "How many pieces? -> ";
	cin >> pieces;
	_employees.emplace_back(new PieceWorker(pieces, price, name));
}

void PaymentSystem::AddHourlyWorker(){
	int salary,hours,standerdhour;
	std::string name;
	cout << "What is the name? -> ";
	cin >> name;
	cout << "How much is the price per hour? -> ";
	cin >> salary;
	cout << "How many hours? -> ";
	cin >> hours;
	cout << "How many hours is the standerd? -> ";
	cin >> standerdhour;
	_employees.emplace_back(new HourlyWorker(hours, salary,standerdhour, name));
}

void PaymentSystem::Print(){
	for (int i = 0; i < _employees.size(); i++){
		cout << "Name     : " << _employees[i]->getName() << endl;
		cout << "Job Type : " << _employees[i]->getType() << endl;
		cout << "Salary   : " << _employees[i]->getSalary() << endl << endl;;
	}
}