#include "Stack.h"

template <typename T>
Stack<T>::Stack(size_t initialCapacity) : top(nullptr), size(0), capacity(initialCapacity) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (size == capacity) {
        capacity *= 2;
    }

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
const T& Stack<T>::peek() const {    // peek() - returns a const reference to the top element
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