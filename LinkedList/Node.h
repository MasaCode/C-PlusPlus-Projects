#pragma once
#include <iostream>
#include <string>
using std::string;


template <class T> class List;
template<class T>

class Node {
private:
    Node<T> *next;
    Node<T> *prev;
    T data;
    
public:
    
//Constructor & Destructor
    Node<T>(){}
    Node<T>(T data){
        next = 0;
        prev = 0;
        this->data = data;
    }
    
    ~Node<T>(){}
    
    
//Access functions
    
    void setNext(Node<T> *var){
        next = var;
    }
    
    Node<T> * getNext(){
        return next;
    }
    
    void setPrev(Node<T> *var){
        prev = var;
    }
    
    Node<T> * getPrev(){
        return prev;
    }
    
    
    void setData(T var){
        data = var;
    }
    
    T getData(){
        return data;
    }
    
    friend class List<T>;
    
};