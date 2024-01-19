#include "Stack.h"

template <typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
    size++;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    Node<T>* temp = top;
    top = top->next;
    delete temp;
    size--;
}

template <typename T>
const T& Stack<T>::peek() const {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return T();
    }

    return top->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
size_t Stack<T>::getSize() const {
    return size;
}

template class Stack<int>;
