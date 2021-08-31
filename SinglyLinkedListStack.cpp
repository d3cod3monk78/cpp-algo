#include <bits/stdc++.h>

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
}