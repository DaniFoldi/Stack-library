//
//  Stack.cpp
//  Stack
//
//  Created by Dani Foldi on 2017. 03. 20..
//  Copyright © 2017. Dani Foldi. All rights reserved.
//

#include "Stack.h"

template<typename type>
Stack<type>::Stack() {
    itemCount = 0;
    size = minimumSize;
    stackItems = (type *) malloc (sizeof(type) * size);

}

template<typename type>
Stack<type>::~Stack() {
    free(stackItems);
    stackItems = NULL;
    size = 0;
    itemCount = 0;
}

template<typename type>
void Stack<type>::setStackSize(const int desiredSize) {
    if (desiredSize <= 0) {
        return 0;
    }
    stackItems = (type *) realloc (stackItems, sizeof(type) * desiredSize);
    size = desiredSize;
}

template<typename type>
void Stack<type>::push(const type item) {
    if (size <= itemCount + 3) {
        setStackSize(size + 3);
    }
    stackItems[itemCount++] = item;
}

template<typename type>
type Stack<type>::popLast() const {
    if (isEmpty()) {
        return NULL;
    } else {
        itemCount -= 1;
        return stackItems[itemCount];
    }
}

template<typename type>
type Stack<type>::peekLast() const {
    if (isEmpty()) {
        return NULL;
    } else {
        return stackItems[itemCount - 1];
    }
}

template<typename type>
type Stack<type>::popFirst() const {
    if (isEmpty()) {
        return NULL;
    } else {
        type thisItem = stackItems[0];
        for (int i = 0; i < size - 1; i++) {
            stackItems[i] = stackItems[i + 1];
        }
        return thisItem;
    }
}

template<typename type>
type Stack<type>::peekFirst() const {
    if (isEmpty()) {
        return NULL;
    } else {
        return stackItems[0];
    }
}

template<typename type>
bool Stack<type>::isEmpty() const {
    return itemCount == 0;
}
