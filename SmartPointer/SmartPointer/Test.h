#pragma once
#include <iostream>
#include <string>

class Test
{
public:
	Test();
	Test(std::string);
	~Test();

	void Print();

private:
	std::string _text;
};

