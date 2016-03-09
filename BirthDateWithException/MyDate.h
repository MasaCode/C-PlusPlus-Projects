#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

template <class T>

class MyDate {
private:
    T day;
    T month;
    T year;
    
public:
  
    void setDate(T year,T month,T day){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    
    
    void getDate(T *day, T *month, T *year){
        *day = this->day;
        *month = this->month;
        *year = this->year;
    }
    void Print(T day,T month,T year);
    
};

template <class T>
void MyDate<T> :: Print(T year,T month, T day){
    cout << "Your Birthday is : " << year << " " << month << " " << day << endl;
    
}