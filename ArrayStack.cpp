#include <bits/stdc++.h>

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
	
	try {
		ArrayStack<int>* arr = new ArrayStack<int>(20);

		for(auto i = 0; i < 10; i++) {
			arr->push(i + 1);
		}

		for(auto i = 0; i < 10; i++) {
			std::cout << arr->top() << std::endl;
			arr->pop();
		}
	}
	catch(const StackEmptyException& e) {
		std::cout << e.getMessage() << std::endl;
	}
	catch(const StackFullException& e) {
		std::cout << e.getMessage() << std::endl;
	}

	return 0;
}