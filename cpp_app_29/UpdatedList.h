#ifndef UpdatedList_h
#define UpdatedList_h

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
    void InsertAt(T value, int position);
    void DeleteAt(int position);
    int Search(T value) const;
    int Replace(T oldValue, T newValue);
    void Reverse();
};

#endif 
