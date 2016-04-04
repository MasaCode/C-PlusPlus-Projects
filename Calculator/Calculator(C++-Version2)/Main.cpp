#include <iostream>
#include "CalculatorBrain.h"

using namespace std;

int main(){
	CalculatorBrain calculation = CalculatorBrain();

	calculation.Input();
	calculation.Print();
	calculation.Calculate();
	calculation.PrintAns();

	return 0;
}