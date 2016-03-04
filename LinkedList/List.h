#include <iostream>
#include <string>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;


template <class T>

class List {
    
    
private:
    Node<T> *start;
    Node<T> *last;
    
//Get the New Node but I dont wanna access this function every where
    Node<T> * getNode(T &data){
        return new Node<T>(data);
    }
    
public:
    
//Constructor & Destructor
    List<T>(){
        start = last = 0;
    }
    ~List<T>(){
        if(this->checkEmpty() == false){ //list is not empty
            Node<T> *current = this->getStart();
            Node<T> *temp;
            while(current != 0){
                temp = current->getNext();
                delete current;
                current = temp;
            }
        }
    }
    
//Access functions
    
    void setStart(Node<T> *var){start = var;}
    Node<T> * getStart(){return start;}
    void setLast(Node<T> *var){last = var;}
    Node<T> * getLast(){return last;}
    
//Utility functions
//In this time, I just create the Node in the function not in the driver
//that's why I just wanna get the data as a argument
    
    void AddtoFront(T &);
    void AddtoBack(T &);
    bool deleteFront();
    bool deleteBack();
    bool checkEmpty(){return start == 0;}
    void print();
        
    
};



template <class T>

void List<T> :: AddtoFront(T &data){
    Node<T> *Add = this->getNode(data);
    Node<T> *current = this->getStart();
    if(this->checkEmpty() == false){ //list is not empty
        Add->setNext(current);
        Add->setPrev(0);
        current->setPrev(Add);
        this->setStart(Add);
    }else{ //list is empty
        this->setStart(Add);
        this->setLast(Add);
    }
}

template <class T>
void List<T> :: AddtoBack(T &data){
    Node<T> *Add = this->getNode(data);
    
    if(this->checkEmpty() == false){ //list is not empty
        Node<T> *current = this->getLast();
        current->setNext(Add);
        Add->setPrev(current);
        Add->setNext(0);
        this->setLast(Add);
    }else{ //list is empty
        this->setStart(Add);
        this->setLast(Add);
    }
}


template <class T>
bool List<T> :: deleteFront(void){
    if(this->checkEmpty() == true){ //list is empty
        cout << "The List is Empty" << endl;
        return false;
    }else{ //list is not empty
        Node<T> *temp = this->getStart();
        Node<T> *current = temp->getNext();
        temp->setNext(0);
        delete temp;
        current->setPrev(0);
        this->setStart(current);
    }
    return true;
}

template <class T>
bool List<T> :: deleteBack(void){
    if(this->checkEmpty() == true){ //list is empty
        cout << "The List is Empty" << endl;
        return false;
    }else{
        Node<T> *temp = this->getLast();
        Node<T> *current = temp->getPrev();
        temp->setPrev(0);
        delete temp;
        current->setNext(0);
        this->setLast(current);
    }
    
    return true;
}


template<class T>
void List<T> :: print(void){
    if(this->checkEmpty() == true){ // list is empty
        cout << "The List is empty " << endl;
        cout << "So There is nothing to show" << endl;
    }else{ //list is not empty
        Node<T> *current = this->getStart();
        int count = 0;
        while(current != 0){
            cout << setw(30) << "Element" << count+1 << " : " << current->getData() << endl;
            current = current->getNext();
            count++;
        }
    }
}
