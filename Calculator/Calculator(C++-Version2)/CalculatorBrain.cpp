#include <iostream>
#include "CalculatorBrain.h"
#include <string>

using namespace std;


void CalculatorBrain::Input(){
	int i = 0, symbolCount = 0, numberCount = 0,Length,valumeOfASCII;
	string input;
	string temp = "";
	cout << "Please enter the fomula.(ex: 1 + 4 * 2)" << endl << "-> ";
	getline(cin, input);
	Length = input.length();
	for (i = 0; i < Length; i++){
		//To get symbols
		if (input[i] == '/' || input[i] == '+' || input[i] == '*' || input[i] == '-'){
			symbols[symbolCount] = input[i];
			symbolCount++;
		}
		//To get Numbers
		valumeOfASCII = int(input[i]);
		if (valumeOfASCII > 47 && valumeOfASCII <= 57){
			while ((valumeOfASCII > 47 && valumeOfASCII <= 57) || input[i] == '.'){
				temp = temp + input[i];
				
				i++;

				valumeOfASCII = int(input[i]);
			} 
			i--;
			Numbers[numberCount] = stod(temp, 0);
			temp = "";
			numberCount++;
		}
	}
	Count = numberCount;
}


void CalculatorBrain::Print(){
	int i = 0;
	for (; i < Count; i++){
		if (i == Count - 1){
			cout << Numbers[i];
		}
		else{
			cout << Numbers[i] << " " << symbols[i] << " ";
		}
	}
}

void CalculatorBrain::Calculate(){
	int i = 0, j = 0;
	double answer;

	for (i = 0; i < Count - 1; i++){
		if (symbols[i] == '*' || symbols[i] == '/'){
			if (symbols[i] == '*'){
				Numbers[i] = Numbers[i] * Numbers[i + 1];
			}
			else if (symbols[i] == '/'){
				Numbers[i] = Numbers[i] / Numbers[i + 1];
			}

			for (j = i + 1; j < Count - 1; j++){
				Numbers[j] = Numbers[j + 1];
				symbols[j - 1] = symbols[j];
			}
			i--;
			Count = Count - 1;
		}
	}
	answer = Numbers[0];
	if (Count > 0){
		for (i = 0; i < Count - 1; i++){
			if (symbols[i] == '+'){
				answer += Numbers[i + 1];
			}
			else if (symbols[i] == '-'){
				answer -= Numbers[i + 1];
			}
		}
	}

	Answer = answer;
}


void CalculatorBrain::PrintAns(){
	cout << " = " << Answer << endl;
}

