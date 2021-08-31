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
	std::string getMessage() const { return this->message; }
};

template <typename E> class Node;
template <typename E> class DoublyLinkedList;

template <typename E> class Node {
	E element;
	Node<E>* prev;
	Node<E>* next;
	friend class DoublyLinkedList<E>;
};

template <typename E> class DoublyLinkedList {
private:
	int entries;
	Node<E>* header;
	Node<E>* tailer;

public:
	DoublyLinkedList();
	~DoublyLinkedList();
	int size() const;
	bool isEmpty() const;
	const E& first() const;
	const E& last() const;
	void addFirst(const E& element);
	void addLast(const E& element);
	void addBetween(const E& element , Node<E>* predecessor , Node<E>* successor);
	void removeFirst();
	void removeLast();
	void removeBetween(Node<E>* p);
};

template <typename E> DoublyLinkedList<E>::DoublyLinkedList() {
	this->entries = 0;
	this->header = new Node<E>();
	this->tailer = new Node<E>();
	this->header->next = this->tailer;
	this->tailer->prev = this->header;
}

template <typename E> DoublyLinkedList<E>::~DoublyLinkedList() {
	while(!this->isEmpty())
		this->removeFirst();
}

template <typename E> int DoublyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool DoublyLinkedList<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& DoublyLinkedList<E>::first() const {
	if(this->isEmpty())
		throw EmptyListException("The list is empty");

	return this->header->next->element;
}

template <typename E> const E& DoublyLinkedList<E>::last() const {
	if(this->isEmpty())
		throw EmptyListException("The list is empty.");
	return this->tailer->prev->element;
}

template <typename E> void DoublyLinkedList<E>::addFirst(const E& element) {
	this->addBetween(element , this->header , this->header->next);
}

template <typename E> void DoublyLinkedList<E>::addLast(const E& element) {
	this->addBetween(element , this->tailer->prev , this->tailer);
}

template <typename E> void DoublyLinkedList<E>::addBetween(const E& element , Node<E>* predecessor , Node<E>* successor) {
	Node<E>* temp = new Node<E>();
	temp->element = element;
	temp->next = successor;
	successor->prev = temp;
	temp->prev = predecessor;
	predecessor->next = temp;
	this->entries++;
}

template <typename E> void DoublyLinkedList<E>::removeFirst() {
	this->removeBetween(this->header->next);
}

template <typename E> void DoublyLinkedList<E>::removeLast() {
	this->removeBetween(this->tailer->prev);
}

template <typename E> void DoublyLinkedList<E>::removeBetween(Node<E>* p) {
	if(this->isEmpty())
		throw EmptyListException("The list is empty");

	Node<E>* predecessor = p->prev;
	Node<E>* successor = p->next;
	predecessor->next = successor;
	successor->prev = predecessor;
	this->entries--;
	delete p;
}

int main(int argc, char const *argv[]) {
	try {
		DoublyLinkedList<int>* arr = new DoublyLinkedList<int>();
		for(auto i = 0; i < 10; i++) {
			arr->addFirst(i + 1);
		}

		std::cout << arr->first() << std::endl;
		std::cout << arr->last() << std::endl;

		for(auto i = 0; i < 3; i++) {
			arr->removeFirst();
			arr->removeLast();
		}

		std::cout << arr->first() << std::endl;
		std::cout << arr->last() << std::endl;
	}
	catch(const EmptyListException& e) {
		std::cout << e.getMessage() << std::endl;
	}

	return 0;
}