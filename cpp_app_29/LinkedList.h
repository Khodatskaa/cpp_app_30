#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();
    ~LinkedList();

    void AddToHead(T value);
    void AddToTail(T value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show() const;
};

#endif 
