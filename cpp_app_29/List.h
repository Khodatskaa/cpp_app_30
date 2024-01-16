#ifndef List_h
#define List_h

#include "Node.h"
#include <iostream>

template <typename T>
class List {
private:
    Node<T>* head;

public:
    List();
    ~List();

    void insert(const T& value);
    void remove(const T& value);
    void print() const;

    List<T>* clone() const;
    List<T>* operator+(const List<T>& other) const;
    List<T>* operator*(const List<T>& other) const;

    void display() const;
};

#endif