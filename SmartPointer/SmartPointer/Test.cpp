#include "Test.h"


Test::Test()
{
}

Test::Test(std::string text) : _text(text){

}

Test::~Test()
{
}

void Test::Print(){
	std::cout << "The string is " << _text << std::endl;
}