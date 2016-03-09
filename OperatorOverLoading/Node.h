#pragma once



#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::ostream;

//template <class T>

class Node{
    friend class List;
    
private:
    Node *next;
    Node *prev;
    //T data;
    int data;
public:
    Node(){
        next = 0;
        prev = 0;
    }
    ~Node(){}
    
    void setNext(Node *varnext){
        this->next = varnext;
    }
    
    Node * getNode(){
        return next;
    }
    
    void setPrev(Node *varprev){
        this->prev = varprev;
    }
    Node * getNext(){
        return next;
    }
    
    
    //void setData(T data){
    void setData(int data){
        this->data = data;
    }
    
    //T getData(){
    int getData(){
        return data;
    }
    
};