#pragma once


#include <iostream>
#include <vector>
#include <string>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;


//template <class T>


class List{
    friend ostream &operator<<(ostream &, List &);
    
    
private:
    Node *start;
    
public:
    List(){
        start = new Node;
    }
    ~List(){
        delete start;
    }
//Utility function
    void AddtoFront(Node *);
    void AddtoBack(Node *);
    
    
//Operator Over Loading function
    
    bool operator==(List &);
    
    bool operator!=(List &right){
        return !(*this == right);
    }
    
    List & operator=(List &);
    
    void operator+(List &);
    
//Access function
    void setStart(Node *varstart){
        this->start = varstart;
    }
    
    Node * getStart(){
        return start;
    }
    
};