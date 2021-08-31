#include <bits/stdc++.h>
#include <string>
#include <exception>

class EmptyListException : public std::exception {
private:
	std::string message;

public:
	EmptyListException(const std::string& err) {
		this->message = err;
	}
	~EmptyListException() {}
	std::string getMessage() const {
		return this->message;
	}
};

template <typename E> class Node;
template <typename E> class CircularlyLinkedList;

template <typename E> class Node {
	E element;
	Node<E>* next;
	friend class CircularlyLinkedList<E>;
};

template <typename E> class CircularlyLinkedList {
private:
	Node<E>* tail;
	int entries;

public:
	CircularlyLinkedList();
	~CircularlyLinkedList();
	int size() const;
	bool isEmpty() const;
	const E& first() const;
	const E& last() const;
	void addFirst(const E& element);
	void addLast(const E& element);
	void removeFirst();
	void advanced();
};

template <typename E> CircularlyLinkedList<E>::CircularlyLinkedList() {
	this->tail = nullptr;
	this->entries = 0;
}

template <typename E> CircularlyLinkedList<E>::~CircularlyLinkedList() {
	while(!this->isEmpty())
		this->removeFirst();
}

template <typename E> int CircularlyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool CircularlyLinkedList<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& CircularlyLinkedList<E>::first() const {
	if(this->isEmpty())
		throw EmptyListException("The list is empty");

	return this->tail->next->element;
}

template <typename E> const E& CircularlyLinkedList<E>::last() const {
	if(this->isEmpty())
		throw EmptyListException("The list is empty");

	return this->tail->element;
}

template <typename E> void CircularlyLinkedList<E>::addFirst(const E& element) {
	Node<E>* head = new Node<E>();
	head->element = element;
	if(this->isEmpty()) {
		this->tail = head;
		this->tail->next = this->tail;
	}
	else {
		head->next = this->tail->next;
		this->tail->next = head;
	}
	this->entries++;
}

template <typename E> void CircularlyLinkedList<E>::addLast(const E& element) {
	this->addFirst(element);
	this->tail = this->tail->next;
}

template <typename E> void CircularlyLinkedList<E>::removeFirst() {
	if(this->isEmpty())
		throw EmptyListException("The list is empty");

	Node<E>* head = this->tail->next;
	if(head == this->tail) this->tail = nullptr;
	else this->tail->next = head->next;
	this->entries--;
	delete head;
}

template <typename E> void CircularlyLinkedList<E>::advanced() { this->tail = this->tail->next; }

int main(int argc, char const *argv[]) {
	try {
		CircularlyLinkedList<int>* arr = new CircularlyLinkedList<int>();

		for(auto i = 0; i < 10; i++) {
			arr->addFirst(i + 1);
		}

		std::cout << arr->first() << std::endl;
		std::cout << arr->last() << std::endl;

		arr->advanced();
		arr->advanced();

		std::cout << arr->first() << std::endl;
		std::cout << arr->last() << std::endl;

		arr->removeFirst();
		arr->removeFirst();

		std::cout << arr->first() << std::endl;
		std::cout << arr->last() << std::endl;
	}
	catch(const EmptyListException& e) {
		std::cout << e.getMessage() << std::endl;	
	}
	return 0;
}