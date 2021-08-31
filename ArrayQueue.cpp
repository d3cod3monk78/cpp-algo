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
	std::string getMessage() const override { return this->message; }
};

class QueueEmptyException : public Exceptions {
public:
	QueueEmptyException(const std::string& err) : Exceptions(err) {}
};

class QueueFullException : public Exceptions {
public:
	QueueFullException(const std::string& err) : Exceptions(err) {}
};

template <typename E> class ArrayQueue {
private:
	enum { DEF_CAPACITY = 100 };

private:
	int f;
	int r;
	E* Queue;
	int capacity;
	int entries;

public:
	ArrayQueue(int cap = DEF_CAPACITY);
	~ArrayQueue();
	int size() const;
	bool isEmpty() const;
	const E& front() const;
	void enqueue(const E& element);
	void dequeue();
};

template <typename E> ArrayQueue<E>::ArrayQueue(int cap) {
	this->capacity = cap;
	this->f = 0;
	this->r = 0;
	this->entries = 0;
	this->Queue = new E[capacity];
}

template <typename E> ArrayQueue<E>::~ArrayQueue() {
	delete [] Queue;
}

template <typename E> int ArrayQueue<E>::size() const { return this->entries; }
template <typename E> bool ArrayQueue<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& ArrayQueue<E>::front() const {
	if(this->isEmpty())
		throw QueueEmptyException("The queue is empty");

	return this->Queue[f];
}

template <typename E> void ArrayQueue<E>::enqueue(const E& element) {
	if(this->r == this->capacity) throw QueueFullException("The queue is full");

	Queue[r++] = element;
	this->entries++;
}

template <typename E> void ArrayQueue<E>::dequeue() {
	if(this->isEmpty()) throw QueueEmptyException("The queue is empty");

	f++;
	this->entries--;
	if(this->isEmpty()) {
		this->f = 0;
		this->r = 0;
	}
}

int main(int argc, char const *argv[]) {
	ArrayQueue<int>* arr = new ArrayQueue<int>(20);

	for(auto i = 0; i < 10; i++){
		arr->enqueue(i + 1);
	}

	std::cout << arr->front() << std::endl;

	arr->dequeue();
	arr->dequeue();
	arr->dequeue();

	std::cout << arr->front() << std::endl;

	return 0;
}