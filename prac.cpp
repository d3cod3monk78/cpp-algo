// Insertion Sort
/*#include <bits/stdc++.h>
void insertionSort(int arr[] , int n) {
	for(auto i = 1; i < n; i++) {
		auto current = arr[i];
		auto j = i - 1;

		while(j >= 0 && current < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = current;

		for(auto k = 0; k < 10; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char const *argv[]) {
	int arr[10] = { 4 , 9 , 1 , 7 , 3 , 8 , 2 , 0 , 5 , 6 };
	insertionSort(arr , 10);

	for(auto i = 0; i < 10; i++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}*/

// selection Sort
/*#include <bits/stdc++.h>
void selectionSort(int arr[] , int n) {
	for(auto i = 0; i < n-1; i++) {
		auto minPos = i;

		for(auto j = i + 1; j < n; j++) {
			if(arr[j] < arr[minPos]) {
				minPos = j;
			}
		}

		if(minPos != i) {
			auto temp = arr[i];
			arr[i] = arr[minPos];
			arr[minPos] = temp;
		}

		for(auto k = 0; k < 10; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char const *argv[]) {
	int arr[10] = { 4 , 9 , 1 , 7 , 3 , 8 , 2 , 0 , 5 , 6 };
	selectionSort(arr , 10);
	return 0;
}*/

//BubbleSort
/*#include <bits/stdc++.h>
void bubbleSort(int arr[] , int n) {
	for(auto i = 0; i < n - 1; i++) {
		bool isSwaped = false;

		for(auto j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSwaped = true;
			}
			for(auto k = 0; k < 10; k++) {
				std::cout << arr[k] << " ";
			}
			std::cout << std::endl;
		}

		for(auto k = 0; k < 10; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		if(!isSwaped) {
			break;
		}
	}
}

int main(int argc, char const *argv[]) {
	int arr[10] = { 4 , 9 , 1 , 7 , 3 , 8 , 2 , 0 , 5 , 6 };
	for(auto k = 0; k < 10; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	bubbleSort(arr , 10);
	return 0;
}*/

/*#include <bits/stdc++.h>
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
}*/

/*#include <bits/stdc++.h>
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
}*/

/*#include <bits/stdc++.h>

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
	return 0;
}*/

/*#include <bits/stdc++.h>

class StackException : public std::exception {
public:
	virtual std::string getMessage() const = 0;
};

class StackEmptyException : public StackException {
private:
	std::string message;

public:
	StackEmptyException(const std::string& err) {
		this->message = err;
	}
	~StackEmptyException() {}
	std::string getMessage() const override { return message; }
};

class StackFullException : public StackException {
private:
	std::string message;

public:
	StackFullException(const std::string& err) {
		this->message = err;
	}
	~StackFullException() {}
	std::string getMessage() const override { return this->message; }
};

template <typename E> class ArrayStack {
private:
	enum { DEF_CAPACITY = 100 };

private:
	int capacity;
	int entries;
	int tos;
	E* Stack;

public:
	ArrayStack(int cap = DEF_CAPACITY);
	~ArrayStack();
	int size() const;
	bool isEmpty() const;
	const E& top() const;
	void pop();
	void push(const E& element);
};

template <typename E> ArrayStack<E>::ArrayStack(int cap) {
	this->capacity = cap;
	this->entries = 0;
	this->tos = -1;
	this->Stack = new E[capacity];
}

template <typename E> ArrayStack<E>::~ArrayStack() { delete [] Stack; }

template <typename E> int ArrayStack<E>::size() const { return this->entries; }
template <typename E> bool ArrayStack<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& ArrayStack<E>::top() const {
	if(this->isEmpty())
		throw StackEmptyException("Stack is empty");

	return this->Stack[tos];
}

template <typename E> void ArrayStack<E>::pop() {
	if(this->isEmpty())
		throw StackEmptyException("The stack is empty");

	tos--;
}

template <typename E> void ArrayStack<E>::push(const E& element) {
	if(this->tos == this->capacity - 1)
		throw StackFullException("Stack is full");

	Stack[++tos] = element;
	this->entries++;
}

int main(int argc, char const *argv[]) {
	ArrayStack<int>* arr = new ArrayStack<int>(20);

	for(auto i = 0; i < 10; i++) {
		arr->push(i + 1);
	}

	for(auto i = 0; i < 10; i++) {
		std::cout << arr->top() << std::endl;
		arr->pop();
	}
	return 0;
}*/

/*#include <bits/stdc++.h>

class ExceptionMessage : public std::exception {
public:
	virtual std::string getMessage() const = 0;
};

class Exceptions : public ExceptionMessage {
private:
	std::string message;

public:
	Exceptions(const std::string& err) { this->message = err; }
	virtual ~Exceptions() {  }
	std::string getMessage() const override { return this->message; }
};

class EmptyListException : public Exceptions {
public:
	EmptyListException(const std::string& err) : Exceptions(err) {}
};

class EmptyStackException : public Exceptions {
public:
	EmptyStackException(const std::string& err) : Exceptions(err) {}
};

template <typename E> class Node;
template <typename E> class SinglyLinkedList;
template <typename E> class SinglyLinkedListStack;

template <typename E> class Node {
	E element;
	Node<E>* next;
	friend class SinglyLinkedList<E>;
};

template <typename E> class SinglyLinkedList {
private:
	int entries;
	Node<E>* head;
	Node<E>* tail;

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
		throw EmptyListException("The list is empty");

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

template <typename E> class SinglyLinkedListStack {
private:
	SinglyLinkedList<E>* Stack;

public:
	SinglyLinkedListStack();
	~SinglyLinkedListStack();
	int size() const;
	bool isEmpty() const;
	const E& top() const;
	void pop();
	void push(const E& element);
};

template <typename E> SinglyLinkedListStack<E>::SinglyLinkedListStack() {
	this->Stack = new SinglyLinkedList<E>();
}

template <typename E> SinglyLinkedListStack<E>::~SinglyLinkedListStack() {
	delete Stack;
}

template <typename E> int SinglyLinkedListStack<E>::size() const { return this->Stack->size(); }
template <typename E> bool SinglyLinkedListStack<E>::isEmpty() const { return this->Stack->isEmpty(); }
template <typename E> const E& SinglyLinkedListStack<E>::top() const { return this->Stack->first(); }
template <typename E> void SinglyLinkedListStack<E>::pop() {
	if(this->isEmpty())
		throw EmptyStackException("The stack is empty");

	return this->Stack->removeFirst();
}

template <typename E> void SinglyLinkedListStack<E>::push(const E& element) {
	this->Stack->addFirst(element);
}

int main(int argc, char const *argv[]) {
	try{
		SinglyLinkedListStack<int>* arr = new SinglyLinkedListStack<int>();

		for(auto i = 0; i < 10l; i++)
			arr->push( i + 1);

		std::cout << arr->top() << std::endl;

		arr->pop();
		arr->pop();
		arr->pop();

		std::cout << arr->top() << std::endl;
	}
	catch(const EmptyListException& e) {
		std::cout << e.getMessage() << std::endl;
	}
	catch(const EmptyStackException& e) {
		std::cout << e.getMessage() << std::endl;
	}

	return 0;
}*/

/*#include <bits/stdc++.h>

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
}*/

/*#include <bits/stdc++.h>

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
}*/

/*#include <bits/stdc++.h>

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
}*/

/*#include <bits/stdc++.h>

class ExceptionMessage : public std::exception {
	virtual std::string getMessage() const = 0;
};

class Exceptions : public ExceptionMessage {
private:
	std::string message;

public:
	Exceptions(const std::string& err) { this->message = err; }
	virtual ~Exceptions() {}
	std::string getMessage() const override { return this->message; }
};

class EmptyVectorException : public Exceptions {
public:
	EmptyVectorException(const std::string& err) : Exceptions(err) {}
};

class VectorFullException : public Exceptions {
public:
	VectorFullException(const std::string& err) : Exceptions(err) {}
};

class OutOfRangeException : public Exceptions {
public:
	OutOfRangeException(const std::string& err) : Exceptions(err) {}
};

template <typename E> class ArrayVector {

private:
	enum { DEF_CAPACITY = 100 };

private:
	int entries;
	E* Vector;
	int capacity;

public:
	ArrayVector(int cap = DEF_CAPACITY);
	~ArrayVector();
	int size() const;
	bool isEmpty() const;
	const E& at(int index) const;
	void set(const int& index , const E& element); //replace the element at i
	void insert(const int& index , const E& element);
	void erase(const int& index);
};

template <typename E> ArrayVector<E>::ArrayVector(int cap) {
	this->capacity = cap;
	this->entries = 0;
	this->Vector = new E[capacity];
}

template <typename E> ArrayVector<E>::~ArrayVector() {
	delete [] Vector;
}

template <typename E> int ArrayVector<E>::size() const { return this->entries; }
template <typename E> bool ArrayVector<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& ArrayVector<E>::at(int index) const {
	if(index < 0 || index >= capacity) throw OutOfRangeException("Your index is out of bounds");
	else if(this->isEmpty()) throw EmptyVectorException("The vector is empty");

	return this->Vector[index];
}

template <typename E> void ArrayVector<E>::set(const int& index , const E& element) {
	if(index < 0 || index >= capacity) throw OutOfRangeException("Your index is out of bounds");
	else if(this->entries == capacity) throw VectorFullException("The vector if full");

	this->Vector[index] = element;
}

template <typename E> void ArrayVector<E>::insert(const int& index , const E& element) {
	if(index < 0 || index >= capacity) throw OutOfRangeException("Your index is out of bounds");
	else if(this->entries == capacity) throw VectorFullException("The vector if full");

	for(auto i = this->entries - 1; i > index - 1; i--) {
		this->Vector[i + 1] = this->Vector[i];
	}
	this->Vector[index] = element;
	this->entries++;
}

template <typename E> void ArrayVector<E>::erase(const int& index) {
	if(index < 0 || index >= capacity) throw OutOfRangeException("Your index is out of bounds");
	else if(this->isEmpty()) throw EmptyVectorException("The vector is empty");

	for(auto i = index + 1; i < entries; i++) {
		this->Vector[i - 1] = this->Vector[i];
	}

	this->entries--;
}

int main(int argc, char const *argv[]) {
	try {
		ArrayVector<int>* arr = new ArrayVector<int>(20);

		for(auto i = 0; i < 10; i++) {
			arr->insert(i , i + 1);
		}

		for(auto i = 0; i < arr->size(); i++) {
			std::cout << arr->at(i) << std::endl;
		}

		arr->set(5 , 20);
		arr->erase(1);
		arr->erase(6);
		arr->erase(9);

		std::cout << std::endl;

		for(auto i = 0; i < arr->size(); i++) {
			std::cout << arr->at(i) << std::endl;
		}
	}
	catch(const Exceptions& e) {
		std::cout << e.getMessage() << std::endl;
	}

	return 0;
}*/

 