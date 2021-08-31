#include <bits/stdc++.h>

class ExceptionMessage : std::exception {
public:
	virtual std::string getMessage() const = 0;
};

class Exceptions : public ExceptionMessage {
private:
	std::string message;

public:
	Exceptions(const std::string& err) {
		this->message = err;
	}
	virtual ~Exceptions() {}
	std::string getMessage() const override { return this->message; }
};

class EmptyListException : public Exceptions {
public:
	EmptyListException(const std::string& err) : Exceptions(err) {}
};

class EmptyDeckException : public Exceptions {
public:
	EmptyDeckException(const std::string& err) : Exceptions(err) {}
};

template <typename E> class Node;
template <typename E> class DoublyLinkedList;
template <typename E> class Deck;

template <typename E> class Node {
	E element;
	Node<E>* prev;
	Node<E>* next;
	friend class DoublyLinkedList<E>;
};

template <typename E> class DoublyLinkedList {
private:
	int entries;
	Node<E>* tailer;
	Node<E>* header;

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
	void removeBetween(Node<E>* node);
};

template <typename E> DoublyLinkedList<E>::DoublyLinkedList() {
	this->entries = 0;
	this->header = new Node<E>();
	this->tailer = new Node<E>();
	this->header->next = this->tailer;
	this->tailer->prev = this->header;
}

template <typename E> DoublyLinkedList<E>::~DoublyLinkedList() {
	while(!this->isEmpty()) this->removeFirst();
}

template <typename E> int DoublyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool DoublyLinkedList<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& DoublyLinkedList<E>::first() const {
	if(this->isEmpty()) throw EmptyListException("The list is empty");
	return this->header->next->element;
}

template <typename E> const E& DoublyLinkedList<E>::last() const {
	if(this->isEmpty()) throw EmptyListException("The list is empty");
	return this->tailer->prev->element;
}

template <typename E> void DoublyLinkedList<E>::addFirst(const E& element) {
	this->addBetween(element , this->header , this->header->next);
}

template <typename E> void DoublyLinkedList<E>::addLast(const E& element) {
	this->addBetween(element , this->tailer->prev , this->tailer);
}

template <typename E> void DoublyLinkedList<E>::addBetween(const E& element , Node<E>* predecessor , Node<E>* successor) {
	Node<E>* node = new Node<E>();
	node->element = element;
	predecessor->next = node;
	node->prev = predecessor;
	successor->prev = node;
	node->next = successor;
	this->entries++;
}

template <typename E> void DoublyLinkedList<E>::removeFirst() {
	this->removeBetween(this->header->next);
}

template <typename E> void DoublyLinkedList<E>::removeLast() {
	this->removeBetween(this->tailer->prev);
}

template <typename E> void DoublyLinkedList<E>::removeBetween(Node<E>* node) {
	if(this->isEmpty()) throw EmptyListException("The list is empty");

	Node<E>* predecessor = node->prev;
	Node<E>* successor = node->next;
	predecessor->next = successor;
	successor->prev = predecessor;
	this->entries--;
	delete node;
}

template <typename E> class DEQueue {
private:
	DoublyLinkedList<E>* Deck;

public:
	DEQueue();
	~DEQueue();
	int size() const;
	bool isEmpty() const;
	const E& front() const;
	const E& back() const;
	void insertFront(const E& element);
	void insertBack(const E& element);
	void removeFront();
	void removeBack();
};

template <typename E> DEQueue<E>::DEQueue() {
	this->Deck = new DoublyLinkedList<E>();
}

template <typename E> DEQueue<E>::~DEQueue() {
	delete Deck;
}

template <typename E> int DEQueue<E>::size() const { return this->Deck->size(); }
template <typename E> bool DEQueue<E>::isEmpty() const { return this->Deck->isEmpty(); }
template <typename E> const E& DEQueue<E>::front() const {
	if(this->isEmpty()) throw EmptyDeckException("The Deck is empty");
	return this->Deck->first();
}

template <typename E> const E& DEQueue<E>::back() const {
	if(this->isEmpty()) throw EmptyDeckException("The Deck is empty");
	return this->Deck->last();
}

template <typename E> void DEQueue<E>::insertFront(const E& element) { this->Deck->addFirst(element); }
template <typename E> void DEQueue<E>::insertBack(const E& element) { this->Deck->addLast(element); }

template <typename E> void DEQueue<E>::removeFront() {
	if(this->isEmpty()) throw EmptyDeckException("The Deck is empty");
	this->Deck->removeFirst();
}

template <typename E> void DEQueue<E>::removeBack() {
	if(this->isEmpty()) throw EmptyDeckException("The Deck is empty");
	this->Deck->removeLast();
}

int main(int argc, char const *argv[]) {
	DEQueue<int>* arr = new DEQueue<int>();

	for(auto i = 0; i < 10; i++) {
		arr->insertFront(i + 1);
	}

	std::cout << arr->front() << std::endl;
	std::cout << arr->back() << std::endl;

	arr->removeFront();
	arr->removeFront();
	arr->removeBack();
	arr->removeBack();

	std::cout << arr->front() << std::endl;
	std::cout << arr->back() << std::endl;

	return 0;
}