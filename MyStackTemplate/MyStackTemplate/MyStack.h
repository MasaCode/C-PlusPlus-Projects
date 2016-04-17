//
//  MyStack.h
//  MyStack
//
//  Created by MoritaMasashi on 2016/04/15.
//  Copyright © 2016年 MoritaMasashi. All rights reserved.
//

#ifndef MyStack_h
#define MyStack_h

template <class T>
class MyStack{
private:
    int size;
    int length;
    T *pointer;
    
public:
    MyStack();
    MyStack(int);
    ~MyStack();
    void push(T);
    void pop();
    void swap(MyStack<T>&);
    bool Empty();
    int Size();
    int Length();
    T top();
    
    //Operator override
    bool operator!=(const MyStack<T>&);
    bool operator==(const MyStack<T>&);
    void operator=(const MyStack<T>&);
    
    //Debug
    void Print();
    
};


#endif /* MyStack_h */
