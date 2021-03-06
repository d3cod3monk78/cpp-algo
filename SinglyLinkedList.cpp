#include <bits/stdc++.h>
#include <exception>
#include <string>

class EmptyListException : public std::exception {
private:
	std::string message;

public:
	EmptyListException(const std::string& err) {
		message = err;
	}
	~EmptyListException() {}
	std::string getMessage() const { return message; }
};

template <typename E> class Node;
template <typename E> class SinglyLinkedList;

template <typename E> class Node {
	E element;
	Node<E>* next;
	friend class SinglyLinkedList<E>;
};

template <typename E> class SinglyLinkedList {
private:
	Node<E>* head;
	Node<E>* tail;
	int entries;

public:
	SinglyLinkedList();
	~SinglyLinkedList();
	int size() const;
	bool isEmpty() const;
	const E& first() const;
	const E& last() const;
	void addFirst(const E& element);
	void addLast(const E& element);
	void removeFirst();
};

template <typename E> SinglyLinkedList<E>::SinglyLinkedList() {
	this->entries = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template <typename E> SinglyLinkedList<E>::~SinglyLinkedList() {
	while(!this->isEmpty())
		this->removeFirst();
}

template <typename E> int SinglyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool SinglyLinkedList<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& SinglyLinkedList<E>::first() const {
	if(this->isEmpty())
		throw EmptyListException("The list is empty!");

	return this->head->element;
}

template <typename E> const E& SinglyLinkedList<E>::last() const {
	if(this->isEmpty())
		throw EmptyListException("The list is empty");

	return this->tail->element;
}

template <typename E> void SinglyLinkedList<E>::addFirst(const E& element) {
	Node<E>* temp = new Node<E>();
	temp->element = element;
	temp->next = this->head;
	this->head = temp;
	if(this->isEmpty()) this->tail = this->head;
	this->entries++;
}

template <typename E> void SinglyLinkedList<E>::addLast(const E& element) {
	if(this->isEmpty())
		this->addFirst(element);
	else {
		Node<E>* temp = new Node<E>();
		temp->element = element;
		temp->next = nullptr;
		this->tail->next = temp;
		this->tail = temp;
		this->entries++;
	}
}

template <typename E> void SinglyLinkedList<E>::removeFirst() {
	if(this->isEmpty())
		throw EmptyListException("The list is empty");

	Node<E>* temp = this->head;
	this->head = this->head->next;
	this->entries--;
	if(this->isEmpty()) this->tail = nullptr;
	delete temp;
}

int main(int argc, char const *argv[]) {
	
	try {
		SinglyLinkedList<int>* S = new SinglyLinkedList<int>();
		
		for(auto i = 0; i < 10; i++) {
			S->addFirst(i + 1);
		}

		std::cout << S->first() << std::endl;
		std::cout << S->last() << std::endl;

		for(auto i = 0; i < 5; i++) {
			S->removeFirst();
		}

		std::cout << S->first() << std::endl;
		std::cout << S->last() << std::endl;

	}
	catch(const EmptyListException& e) {
		std::cout << e.getMessage() << std::endl;
	} 

	return 0;
}