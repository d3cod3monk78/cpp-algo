#include <bits/stdc++.h>

class ExceptionMessage : public std::exception {
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
	std::string getMessage() const override {
		return this->message;
	}
};

class EmptyListException : public Exceptions {
public:
	EmptyListException(const std::string& err) : Exceptions(err) {}
};

class EmptyQueueException : public Exceptions {
public:
	EmptyQueueException(const std::string& err) : Exceptions(err) {}
};

class QueueFullException : public Exceptions {
public:
	QueueFullException(const std::string& err) : Exceptions(err) {}
};

template <typename E> class Node;
template <typename E> class CircularlyLinkedList;
template <typename E> class CircularlyLinkedListQueue;

template <typename E> class Node {
	E element;
	Node<E>* next;
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
	void advance();
};

template <typename E> CircularlyLinkedList<E>::CircularlyLinkedList() {
	this->entries = 0;
	this->tail = nullptr;
}

template <typename E> CircularlyLinkedList<E>::~CircularlyLinkedList() {
	while(!this->isEmpty())
		this->removeFirst();
}

template <typename E> int CircularlyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool CircularlyLinkedList<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& CircularlyLinkedList<E>::first() const {
	if(this->isEmpty()) throw EmptyListException("The list is empty");

	return this->tail->next->element;
}

template <typename E> const E& CircularlyLinkedList<E>::last() const {
	if(this->isEmpty()) throw EmptyListException("The list is empty");

	return this->tail->element;
}

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
	this->advance();
}

template <typename E> void CircularlyLinkedList<E>::removeFirst() {
	if(this->isEmpty()) throw EmptyListException("The list is empty.");

	Node<E>* head = this->tail->next;
	if(this->tail == head) this->tail = nullptr;
	else this->tail->next = head->next;
	this->entries--;
	delete head;
}

template <typename E> void CircularlyLinkedList<E>::advance() {
	if(this->isEmpty()) throw EmptyListException("The list is empty");
	this->tail = this->tail->next;
}

template <typename E> class CircularlyLinkedListQueue {
private:
	CircularlyLinkedList<E>* Queue;

public:
	CircularlyLinkedListQueue();
	~CircularlyLinkedListQueue();
	int size() const;
	bool isEmpty() const;
	const E& front() const;
	void enqueue(const E& element);
	void dequeue();
};

template <typename E> CircularlyLinkedListQueue<E>::CircularlyLinkedListQueue() {
	this->Queue = new CircularlyLinkedList<E>();
}

template <typename E> CircularlyLinkedListQueue<E>::~CircularlyLinkedListQueue() {
	delete this->Queue;
}

template <typename E> int CircularlyLinkedListQueue<E>::size() const { return this->Queue->size(); }
template <typename E> bool CircularlyLinkedListQueue<E>::isEmpty() const { return this->Queue->isEmpty(); }
template <typename E> const E& CircularlyLinkedListQueue<E>::front() const {
	if(this->isEmpty()) throw EmptyQueueException("The queue is empty");
	return this->Queue->first();
}

template <typename E> void CircularlyLinkedListQueue<E>::enqueue(const E& element) {
	this->Queue->addLast(element);
}

template <typename E> void CircularlyLinkedListQueue<E>::dequeue() {
	if(this->isEmpty()) throw EmptyQueueException("The queue is empty");
	this->Queue->removeFirst();
}

int main(int argc, char const *argv[]) {
	CircularlyLinkedListQueue<int>* arr = new CircularlyLinkedListQueue<int>();

	for(auto i = 0; i < 10; i++) {
		arr->enqueue(i + 1);
	}

	std::cout << arr->front() << std::endl;

	arr->dequeue();
	arr->dequeue();
	arr->dequeue();

	std::cout << arr->front() << std::endl;


	return 0;
}