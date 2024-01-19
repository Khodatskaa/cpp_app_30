#ifndef Stack_h
#define Stack_h

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;
    size_t size;

public:
    Stack();
    ~Stack();

    void push(const T& value);
    void pop();
    const T& peek() const;
    bool isEmpty() const;
    size_t getSize() const;
};

#endif