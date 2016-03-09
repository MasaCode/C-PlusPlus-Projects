#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include <sstream>
#include "MyDate.h"
//#include "Exceptions.h"


using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::atoi;
using std::istringstream;

void PrintTime(tm *timeinfo){
    
    printf ( "Current local time and date: %s", asctime (timeinfo) );
}

template <class T>
void InputDate(T year,T month, T day){
    MyDate<T> birthday;
    birthday.setDate(year,month,day);
    birthday.Print(year,month,day);
    
    
}

void InvalidCheck(int year,int month,int day,int Nyear){
    if(year<0 || month<0 || day<0){
        cout << "NegativeException" << endl;
        //throw NegativeException();
    }
    if(day > 31){
        cout << "InvalidDayEntryException" << endl;
        //throw InvalidDayEntryException();
    }else if(month > 12){
        cout << "InvalidMonthEntryException" << endl;
        //throw InvalidMonthEntryException();
    }else if(year > Nyear){
        cout << "InvalidYearEntryException" << endl;
        //throw InvalidYearEntryException();
    }
}

void input(int *year , int *month , int *day,string *Syear,string *Smonth,string *Sday){
    cout << "Please enter your BirthDate" << endl;;
    
    cout << "Year : ";
    cin >> *Syear;
    istringstream is(*Syear);
    is >> *year;
    
    
    is.clear();
    cout << "Month : ";
    cin >> *Smonth;
    is.str(*Smonth);
    is >> *month;
    
    is.clear();
    cout << "Day : ";
    cin >> *Sday;
    is.str(*Sday);
    is >> *day;

}

int main(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int Tyear = (int)(timeinfo->tm_year + 1900);
    
    PrintTime(timeinfo); // for printing time
    string Syear,Smonth,Sday;
    int year,month,day;
    
    //try{
        input(&year,&month,&day,&Syear,&Smonth,&Sday);
        if(year == 0 || month == 0 || day == 0){
            InputDate<string>(Syear,Smonth,Sday);
        }else{
            InvalidCheck(year,month,day,Tyear);
            InputDate<int>(year,month,day);
        }
    //}
    
/*
    catch(NegativeException &NegativeException){
        cout << "Exception occurred " << NegativeException.what() << endl;
    }
    catch(InvalidDayEntryException &InvalidDayEntryException){
        cout << "Exception occurred " << InvalidDayEntryException.what() << endl;
    }
    catch(InvalidMonthEntryException &InvalidMonthEntryException){
        cout << "Exception occurred " << InvalidMonthEntryException.what() << endl;
    }
    catch(InvalidYearEntryException &InvalidYearEntryException){
        cout << "Exception occurred " << InvalidYeaerEntryException.what() << endl;
    }
 
    
*/
    return 0;
}