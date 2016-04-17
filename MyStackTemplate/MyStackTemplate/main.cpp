//
//  main.cpp
//  MyStack
//
//  Created by MoritaMasashi on 2016/04/15.
//  Copyright © 2016年 MoritaMasashi. All rights reserved.
//

#include <iostream>
#include <string>
#include "MyStack.h"
#include "MyStack.cpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, const char * argv[]) {
    MyStack<int> Stack1;
    MyStack<int> Stack2(20);
    Stack1.push(9);
    Stack1.push(8);
    Stack1.Print();
    cout << "The Element of MyStack is " << Stack1.top() << endl;
    Stack1.pop();
    Stack1.Print();
    string isEmpty = Stack1.Empty() == true ? "true" : "false";
    cout << "This stack is empty? : " << isEmpty << endl;

    
    //swap
    for(int i = 0; i < 10; i++){
        Stack1.push(i);
        Stack2.push(9-i);
    }
    
    cout << "MyStack 1 : ";
    Stack1.Print();
    cout << "MyStack 2 : ";
    Stack2.Print();
    
    cout << "Try to sawp two MyStacks." << endl;
    Stack1.swap(Stack2);

    cout << "MyStack 1 : ";
    Stack1.Print();
    cout << "MyStack 2 : ";
    Stack2.Print();
    

    //for testing the resize system.....So far it works so well.
    MyStack<double> Stack3(2);
    Stack3.push(2.1);
    Stack3.push(5.9);
    Stack3.push(1.33);
    Stack3.push(9.00);
    Stack3.Print();
    cout << "The size of Stack3 is " << Stack3.Size() << endl;
    
 
    return 0;
}
