#include <iostream>
#include <string>
#include <iomanip>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::exception;




class NegativeException : public exception{
public:
    NegativeException(): exception("attempt to enter negative number"){}
    
};


class InvalidDayEntryException : public exception{
    public:
    InvalidDayEntryException():exception("Attempt to enter wrong number"){}
};

class InvalidMonthEntryException : public exception{
    public:
    InvalidMonthEntryException():exception("Attempt to enter wrong number"){}
};

class InvalidYearEntryException : public exception{
    public:
    InvalidYearEntryException():exception("Attempt to enter wrong number"){}
};