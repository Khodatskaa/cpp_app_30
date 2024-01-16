#ifndef Stack_h
#define Stack_h

#include "Node.h"
#include <iostream>

template <typename T>
class Stack {
private:
    Node<T>* top;  
    size_t size;
    size_t capacity;

public:
    Stack(size_t initialCapacity = 10);
    ~Stack();

    void push(const T& value);
    void pop();
    const T& peek() const;
    bool isEmpty() const;
    size_t getSize() const;
};

#endif
