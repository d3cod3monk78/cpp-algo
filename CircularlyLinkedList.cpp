#include <bits/stdc++.h>

template <typename E> class Node;
template <typename E> class CircularlyLinkedList;

template <typename E> class Node {
	Node<E>* next;
	E element;
	friend class CircularlyLinkedList<E>;
};

template <typename E> class CircularlyLinkedList {
private:
	int entries;
	Node<E>* tail;

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
	void rotate();
};

template <typename E> CircularlyLinkedList<E>::CircularlyLinkedList : entries(0) , tail(nullptr) {}
template <typename E> CircularlyLinkedList<E>::~CircularlyLinkedList() {}

template <typename E> int CircularlyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool CircularlyLinkedList<E>::isEmpty() const { return this->entries == 0; }
template <typename E> const E& CircularlyLinkedList<E>::first() const { return this->tail->next->element; }
template <typename E> const E& CircularlyLinkedList<E>::last() const { return this->tail->element; }

template <typename E> void CircularlyLinkedList<E>::addFirst(const E& element) {
	Node<E>* temp = new Node<E>();
	temp->element = element;
	if(this->isEmpty()) {
		this->tail = temp;
		this->tail->next = this->tail;
	}
	else {
		temp->next = this->tail->next;
		this->tail->next = temp;
	}
	this->entries++;
}

template <typename E> void CircularlyLinkedList<E>::addLast(const E& element) {
	this->addFirst(element);
	this->tail = this->tail->next;
}

template <typename E> void CircularlyLinkedList<E>::removeFirst() {
	Node<E>* head = this->tail->next;
	if(head == this->tail) {
		this->tail = nullptr;
	}
	else {
		this->tail->next = head->next;
	}
	this->entries--;
	delete head;
}

template <typename E> void CircularlyLinkedList<E>::rotate() { this->tail = this->tail->next; }