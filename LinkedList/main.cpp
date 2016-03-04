#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iomanip>
using std::setw;

#include <sstream>
using std::stringstream;

#include "Node.h"
#include "List.h"

int Menu(){
    int choice;
    cout << setw(20) << "MENU" << endl;
    cout << setw(20) << "1 . Add to the Front            " << endl;
    cout << setw(20) << "2 . Add to the Back             " << endl;
    cout << setw(20) << "3 . Delete beginning of the List" << endl;
    cout << setw(20) << "4 . Delete end of the List      " << endl;
    cout << setw(20) << "5 . Print out the all Lists     " << endl;
    cout << setw(20) << "6 . Exit                        " << endl;
    
    do{
        cout << "Your choice : ";
        cin >> choice;
    }while(choice > 6);
    return choice;
}


template< class T>


void Do(List<T> &list,const string &type){
    int choice;
    T data;
    do{
        choice = Menu();
        if(choice > 2){
            if(choice == 3){
                list.deleteFront();
            }else if(choice == 4){
                list.deleteBack();
            }else if(choice == 5){
                cout << "The List : " << endl;
                list.print();
            }else{
                break;
            }
        }else{
            cout << "Please enter the data which is " << type << " : " ;
            cin >> data;
            if(choice == 1){
                list.AddtoFront(data);
            }else if(choice == 2){
                list.AddtoBack(data);
            }
        }
    }while(true);
}


int main(){
    char *type = new char[20];
    char *decision = new char[10];
    do{
        do{
            cout << "What king of List would you like to create : ";
            cin >> type;
        }while(!(((strcmp(type,"int")) == 0) || ((strcmp(type,"double")) ==0) || ((strcmp(type,"char")) == 0) || ((strcmp(type,"string")) == 0) || ((strcmp(type,"float")) == 0)));
    
        if((strcmp(type,"int")) == 0){
            List< int > integerList;
            Do( integerList, "integer" );
        }else if((strcmp(type,"char")) == 0){
            List< char > charList;
            Do( charList, "char" );
        }else if((strcmp(type,"string")) == 0){
            List< string > stringList;
            Do( stringList, "string" );
        }else if((strcmp(type,"double")) == 0){
            List< double > doubleList;
            Do( doubleList, "double" );
        }else if((strcmp(type,"float")) == 0){
            List< float > floatList;
            Do( floatList, "float" );
        }else{
            cout << "I couldn't understand what type of list you wanna create" << endl;
        }
        do{
            cout << "Do you wanna continue?(yes/no) : ";
            cin >> decision;
        }while(!(((strcmp(decision,"yes")) == 0) || ((strcmp(decision,"Yes")) == 0) || ((strcmp(decision,"no")) == 0) || ((strcmp(decision,"No")) == 0)));
        
        
    }while(((strcmp(decision,"yes")) ==0) || ((strcmp(decision,"Yes")) == 0));
    delete[] type;
    delete[] decision;
    return 0;
}

