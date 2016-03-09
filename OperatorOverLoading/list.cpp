#include "list.h"

#include <iostream>
#include <string>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::setw;


//Utility function

void List :: AddtoBack(Node *current){
    Node *location = this->getStart();
    while(location->getNext() != 0){
        location = location->getNext();
    }
    
    location->setNext(current);
    current->setPrev(location);
    current->setNext(0);
    
}


void List :: AddtoFront(Node *current){
    Node *location = this->getStart();
    current->setNext(location);
    location->setPrev(current);
    this->setStart(current);
    
}


//Operator Over Loading function

bool List:: operator==(List &right){
    Node *rcurrent = right.getStart();
    Node *lcurrent = this->getStart();
    int lcount=0,rcount=0;
    
    while(lcurrent != 0){
        lcount++;
        lcurrent = lcurrent->getNext();
    }
    while(rcurrent != 0){
        rcount++;
        rcurrent = rcurrent->getNext();
    }
    
    if(lcount != rcount){
        return false;
    }else{
        lcurrent = right.getStart();
        rcurrent = this->getStart();
        for(int i=0; i<rcount; i++){
            if(lcurrent->getData() != rcurrent->getData()){
                return false;
            }
            lcurrent = lcurrent->getNext();
            rcurrent = rcurrent->getNext();
        }
        
    }
    
    return true;
}


void List :: operator+(List &right){
    Node *lcurrent = this->getStart();
    while(lcurrent->getNext() != 0){
        lcurrent = lcurrent->getNext();
    }
    lcurrent->setNext(right.start);
    right.start->setPrev(lcurrent);

}

List & List :: operator=(List &right){
    Node *lcurrent = this->getStart();
    Node *rcurrent = right.getStart();
    int lcount=0,rcount=0;
    if(rcurrent == 0 || lcurrent == 0){
        cout << "Unsuccessfuly done it." << endl;
    }else{
        while(lcurrent != 0) {
            lcount++;
            lcurrent = lcurrent->getNext();
        }
        while(rcurrent != 0){
            rcount++;
            rcurrent = rcurrent->getNext();
        }
        if(lcount != rcount){
            lcurrent = this->getStart();
            Node *temp;
            while(lcurrent != 0){
                temp = lcurrent->getNext();
                delete lcurrent;
                lcurrent = temp;
            }
            
            start = new Node;
            
        }
        lcurrent = this->getStart();
        rcurrent = right.getStart();
        for(int i=0; i<rcount; i++){
            Node *Data = new Node;
            Data->setData(rcurrent->getData());
            if(i == 0){
                lcurrent->setData(Data->getData());
                lcurrent->setNext(0);
                lcurrent->setPrev(0);
            }else{
                lcurrent->setNext(Data);
                Data->setPrev(lcurrent);
                Data->setNext(0);
                lcurrent = Data;
            }
            rcurrent = rcurrent->getNext();
        }
    }
    
    return *this;
}


//friend function

ostream & operator <<(ostream &output , List &print){
    int element=0;
    Node *current = print.getStart();
    while(current != 0){
        cout << setw(20) << "Element" << element+1 << " : " << current->getData() << endl;
        element++;
        current = current->getNext();
    }
    return output;
}
