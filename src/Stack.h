//
//  Stack.cpp
//  Stack
//
//  Created by Dani Foldi on 2017. 03. 20..
//  Copyright © 2017. Dani Foldi. All rights reserved.
//

#ifndef STACK_H
#define STACK_H
#include <Arduino.h>
template<typename type>
class Stack {
public:
    Stack();
    ~Stack();
    type popFirst() const;
    type peekFirst() const;
    type peekLast() const;
    type popLast() const;
    void push(const type item);
    int count() const;
    bool isEmpty() const;
private:
    void setStackSize(const int size);
    int size;
    int itemCount;
    int minimumSize = 2;
    type * stackItems;
};
#endif
