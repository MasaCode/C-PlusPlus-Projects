#ifndef CalculatorBrain_h
#define CalculatorBrain_h

class CalculatorBrain{
private:
	double Numbers[30];
	char symbols[30];
	double Answer;
	int Count;

public:
	void Input();
	void Print();
	void Calculate();
	void PrintAns();
	CalculatorBrain(){ Answer = 0; }
};

#endif /* CalculatorBrain_h */