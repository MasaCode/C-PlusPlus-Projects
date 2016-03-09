#include "Node.h"
#include "list.h"


#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setw;



int Menu(){
    int choice;
    cout << setw(20) << "MENU" << endl;
    cout << setw(20) << "0 . create the list                  " << endl;
    cout << setw(20) << "1 . Check the 2 list(==)             " << endl;
    cout << setw(20) << "2 . Check the 2 list(!=)             " << endl;
    cout << setw(20) << "3 . Add to the list to list(+)       " << endl;
    cout << setw(20) << "4 . Assign to the list to new list(=)" << endl;
    cout << setw(20) << "5 . Print out all list               " << endl;
    cout << setw(20) << "6 . Exit                             " << endl;
    do{
        cout << "Your choice : ";
        cin >> choice;
    }while(choice > 6);
    return choice;
}


int AddMenu(){
    int choice;
    cout << setw(20) << "MENU" << endl;
    cout << setw(20) << "1 . Add to front" << endl;
    cout << setw(20) << "2 . Add to back " << endl;
    
    do{
        cout << "Your choice : ";
        cin >> choice;
    }while(choice > 2);
    
    return choice;
}

int main(){
    vector <List> lists(20);
    int choice,count=0,addchoice;
    int location1=0,location2=0;
    while(true){
        choice = Menu();
        if(choice == 0){
            int data,createcount = 0;
            char *decision = new char[20];
            do{
                Node *current = new Node;
                cout << "Please enter the number of data : ";
                cin >> data;
                current->setData(data);
                if(createcount == 0){
                    current->setNext(0);
                    current->setPrev(0);
                    lists[count].setStart(current);
                }else{
                    addchoice = AddMenu();
                    if(addchoice == 1){
                        lists[count].AddtoFront(current);
                    }else if(addchoice == 2){
                        lists[count].AddtoBack(current);
                    }
                }
                createcount++;
                do{
                    cout << "Do you wanna continue?(yes/no) : ";
                    cin >> decision;
                    }while(!(((strcmp(decision,"no")) == 0) || ((strcmp(decision,"No"))==0) || ((strcmp(decision,"Yes")) == 0) || ((strcmp(decision,"yes")) == 0)));
                    
            }while(((strcmp(decision,"Yes")) == 0) || ((strcmp(decision,"yes")) == 0));
            delete[] decision;
            count++;
        }else if(choice == 1){
            if(count < 2){
                cout << "There is not enough lists to compare" << endl;
            }else{
                cout << "Now there are " << count << " lists." << endl;
                cout << "Which list would you like to compare?" << endl;
                cout << "Plese enter the number of list" << endl;
                cout << "List 1 : ";
                cin >> location1;
                cout << "List 2 : ";
                cin >> location2;
                location1 = location1-1; location2 = location2-1;
                if(lists[location1] == lists[location2]){
                    cout << "Thease two Lists are equal" << endl;
                }else{
                    cout << "Thease two Lists are not equal" << endl;
                }
            }
            
        }else if(choice == 2){
            if(count < 2){
                cout << "There is not enough lists to compare" << endl;
            }else{
                cout << "Now there are " << count << " lists." << endl;
                cout << "Which list would you like to compare?" << endl;
                cout << "Plese enter the number of list" << endl;
                cout << "List 1 : ";
                cin >> location1;
                cout << "List 2 : ";
                cin >> location2;
                location1 = location1-1; location2 = location2-1;
                if(lists[location1] != lists[location2]){
                    cout << "Thease two Lists are not equal" << endl;
                }else{
                    cout << "Thease two Lists are equal" << endl;
                }
            }
        }else if(choice == 3){
            cout << "Now there are " << count << " lists." << endl;
            cout << "Which list would you like to add?" << endl;
            cout << "Plese enter the number of list" << endl;
            cout << "List 1 : ";
            cin >> location1;
            cout << "List 2 : ";
            cin >> location2;
            location1 = location1-1; location2 = location2-1;
            lists[location1] + lists[location2];
            cout << "The List[" << location1+1 << "] : " << endl << lists[location1];
        }else if(choice == 4){
            cout << "Now there are " << count << " lists." << endl;
            cout << "Which list would you like to copy to new List?" << endl;
            cout << "Plese enter the number of list" << endl;
            cout << "Base List : ";
            cin >> location1;
            location1 = location1-1;
            lists[count] = lists[location1];
            cout << "New List : " << endl << lists[location1];
            count++;
        }else if(choice == 5){
            for(int i = 0; i<count; i++){
                cout << "The List[" << i+1 << "] : " << endl << lists[i];
            }
        }else{
            break;
        }
        
        
    }
    return 0;
}