#include <iostream>
#include "MyStack.h"

using std::cout;
using std::endl;

template<class T>
MyStack<T>::~MyStack(){
    delete[] pointer;
}

template <class T>
MyStack<T>::MyStack(){
    size = 10;
    pointer = new T[size];
    
    for(int i = 0; i < size; i++)
        pointer[i] = NULL;
}

template<class T>
MyStack<T>::MyStack(int _size){
    size = _size > 0 ? _size : 10;
    pointer = new T[size];
    
    for(int i = 0; i < size; i++)
        pointer[i] = NULL;
}

template<class T>
void MyStack<T>::push(T data){
    int i = 0;
    if(size == length){
        T *temp = new T[size + 10];
        for(i = 0; i < size; i++)
            temp[i] = this->pointer[i];
        for(i = size; i < size + 10; i++)
            temp[i] = NULL;
        size += 10;
        delete[] pointer;
        pointer = new T[size];
        for(i = 0; i < size; i++)
            pointer[i] = temp[i];
        delete[] temp;
        
        //For Debugging
        //cout << "Resize the Stack object." << endl;
    }
    
    for(i = size-1; i >= 0; i--)
        pointer[i] = pointer[i-1];
    
    length++;
    pointer[0] = data;
}

template<class T>
void MyStack<T>::pop(){
    for(int i = 0; i < size-1; i++)
        pointer[i] = pointer[i + 1];
    
    length--;
    pointer[size-1] = NULL;
}

template<class T>
void MyStack<T>::swap(MyStack<T> &other){
    T *temp;
    int tempSize,tempLength;
    int i=0;
    
    tempSize = this->size;
    tempLength = this->length;
    temp = new T[tempSize];
        
    for(i = 0; i < tempSize; i++)
        temp[i] = this->pointer[i];
        
    delete[] this->pointer;
    this->size = other.size;
    this->length = other.length;
    this->pointer = new T[this->size];
    for(i = 0; i < this->size; i++)
        this->pointer[i] = other.pointer[i];
        
    delete[] other.pointer;
    other.size = tempSize;
    other.length = tempLength;
    other.pointer = new T[other.size];
    for(i = 0; i < other.size; i++)
        other.pointer[i] = temp[i];
}

template<class T>
bool MyStack<T>::Empty(){
    for(int i = 0; i < size; i ++){
        if(pointer[i] != NULL)
            return false;
    }
    return true;
}

template<class T>
T MyStack<T>::top(){
    return pointer[0];
}

template<class T>
int MyStack<T>::Size(){
    return size;
}

template<class T>
int MyStack<T>::Length(){
    return length;
}

//Operator override

template<class T>
bool MyStack<T>::operator!=(const MyStack<T> &other){
    return !(*this == other);
}

template<class T>
bool MyStack<T>::operator==(const MyStack<T> &other){
    if(this->size != other.size)
        return false;
    
    if(this->length != other.length)
        return false;
    
    for(int i = 0; i < this->size; i++){
        if(this->pointer[i] != other.pointer[i])
            return false;
    }
    
    return true;
}

template<class T>
void MyStack<T>::operator=(const MyStack<T> &other){
    
    
    if(this != other){
        if(this->size != other.size){
            delete[] this->pointer;
            this->size = other.size;
            this->pointer = new T[this->size];
        }
        
        this->length = other.length;
        for(int i = 0; i < this->size; i++)
            this->pointer[i] = other.pointer[i];
    }
}




//Debug
template<class T>
void MyStack<T>::Print(){
    for(int i = 0; i < size; i++)
        cout << pointer[i] << " ";
    
    cout << endl;
}

