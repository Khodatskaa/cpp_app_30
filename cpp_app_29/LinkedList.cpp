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
		head = newNode;
		tail = newNode;
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
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::DeleteFromHead() {
	if (head == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	Node<T>* temp = head;

	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		head = head->next;
	}

	delete temp;
}

template <typename T>
void LinkedList<T>::DeleteFromTail() {
	if (head == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	Node<T>* temp = head;

	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		while (temp->next != tail) {
			temp = temp->next;
		}

		temp->next = nullptr;
		tail = temp;
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
	if (head == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	Node<T>* temp = head;

	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}

	std::cout << std::endl;
}
