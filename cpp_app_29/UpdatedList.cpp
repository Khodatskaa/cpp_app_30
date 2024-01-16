#include "UpdatedList.h"

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

template <typename T>
void LinkedList<T>::InsertAt(T value, int position) {
	if (position < 0) {
		return;
	}

	if (position == 0) {
		AddToHead(value);
		return;
	}

	Node<T>* newNode = new Node<T>(value);
	Node<T>* current = head;
	int currentPosition = 0;

	while (current != nullptr && currentPosition < position - 1) {
		current = current->next;
		currentPosition++;
	}

	if (current == nullptr) {
		return;
	}

	newNode->next = current->next;
	current->next = newNode;
}

template <typename T>
void LinkedList<T>::DeleteAt(int position) {
	if (position < 0) {
		return;
	}

	if (position == 0) {
		DeleteFromHead();
		return;
	}

	Node<T>* current = head;
	int currentPosition = 0;

	while (current != nullptr && currentPosition < position - 1) {
		current = current->next;
		currentPosition++;
	}

	if (current == nullptr || current->next == nullptr) {
		return;
	}

	Node<T>* temp = current->next;
	current->next = temp->next;
	delete temp;
}

template <typename T>
int LinkedList<T>::Search(T value) const {
	Node<T>* current = head;
	int currentPosition = 0;

	while (current != nullptr) {
		if (current->data == value) {
			return currentPosition;
		}

		current = current->next;
		currentPosition++;
	}

	return -1;
}

template <typename T>
int LinkedList<T>::Replace(T oldValue, T newValue) {
	Node<T>* current = head;
	int currentPosition = 0;
	int count = 0;

	while (current != nullptr) {
		if (current->data == oldValue) {
			current->data = newValue;
			count++;
		}

		current = current->next;
		currentPosition++;
	}

	return count;
}

template <typename T>
void LinkedList<T>::Reverse() {
	Node<T>* current = head;
	Node<T>* previous = nullptr;
	Node<T>* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	head = previous;
}

template class LinkedList<int>;
