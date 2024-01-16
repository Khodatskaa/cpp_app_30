#include "List.h"

template <typename T>
List<T>::List() : head(nullptr) {}

template <typename T>
List<T>::~List() {
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* next = current->next;
		delete current;
		current = next;
	}
}

template <typename T>
void List<T>::insert(const T& value) {
	Node<T>* newNode = new Node<T>(value);
	newNode->next = head;
	head = newNode;
}

template <typename T>
void List<T>::remove(const T& value) {
	Node<T>* current = head;
	Node<T>* previous = nullptr;
	while (current != nullptr) {
		if (current->data == value) {
			if (previous == nullptr) {
				head = current->next;
			}
			else {
				previous->next = current->next;
			}
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}
}

template <typename T>
void List<T>::print() const {
	Node<T>* current = head;
	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template <typename T>
List<T>* List<T>::clone() const {
	List<T>* newList = new List<T>();
	Node<T>* current = head;
	while (current != nullptr) {
		newList->insert(current->data);
		current = current->next;
	}
	return newList;
}

template <typename T>
List<T>* List<T>::operator+(const List<T>& other) const {
	List<T>* newList = clone();
	Node<T>* current = other.head;
	while (current != nullptr) {
		newList->insert(current->data);
		current = current->next;
	}
	return newList;
}

template <typename T>
List<T>* List<T>::operator*(const List<T>& other) const {
	List<T>* newList = new List<T>();
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* currentOther = other.head;
		while (currentOther != nullptr) {
			if (current->data == currentOther->data) {
				newList->insert(current->data);
				break;
			}
			currentOther = currentOther->next;
		}
		current = current->next;
	}
	return newList;
}

template<typename T>
void List<T>::display() const{
	Node<T>* current = head;
	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template class List<int>;