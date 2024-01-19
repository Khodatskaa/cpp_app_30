#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    DeleteAll();
}

template <typename T>
void LinkedList<T>::AddToHead(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void LinkedList<T>::AddToTail(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::DeleteFromHead() {
    if (head == nullptr) {
        return;
    }

    Node<T>* temp = head;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
    }

    delete temp;
}

template <typename T>
void LinkedList<T>::DeleteFromTail() {
    if (head == nullptr) {
        return;
    }

    Node<T>* temp = tail;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        Node<T>* current = head;

        while (current->next != tail) {
            current = current->next;
        }

        tail = current;
        tail->next = nullptr;
    }

    delete temp;
}

template <typename T>
void LinkedList<T>::DeleteAll() {
    while (head != nullptr) {
        DeleteFromHead();
    }
}

template <typename T>
void LinkedList<T>::Show() const {
    Node<T>* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

template class LinkedList<int>;
