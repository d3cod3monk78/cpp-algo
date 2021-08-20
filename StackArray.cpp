#include <bits/stdc++.h>
#include <string>
#include <exception>

class StackEmpty : public std::exception {
private:
	std::string message;

public:
	StackEmpty(const std::string& err) {
		message = err;
	}
	~StackEmpty() {}
	std::string getMessage() const { return message; }
};

class StackFull : public std::exception {
private:
	std::string message;

public:
	StackFull(const std::string& err) {
		message = err;
	}
	~StackFull() {}
	std::string getMessage() const { return message; }
};

template <typename E> class StackArray {
private:
	enum { DEF_CAPACITY = 100 };
	E* S;
	int capacity;
	int t;

public:
	StackArray(int cap = DEF_CAPACITY);
	~StackArray();
	int size() const;
	bool isEmpty() const;
	const E& top() const;
	void push(const E& element);
	void pop();
};

template <typename E> StackArray<E>::StackArray(int cap) {
	S = new E[cap];
	capacity = cap;
	t = -1;
}
template <typename E> StackArray<E>::~StackArray() {
	delete [] S;
}

template <typename E> int StackArray<E>::size() const { return this->t + 1; }
template <typename E> bool StackArray<E>::isEmpty() const { return this->t == -1; }

template <typename E> const E& StackArray<E>::top() const {
	if(this->isEmpty()) throw StackEmpty("The stack is empty");
	return this->S[t];
}

template <typename E> void StackArray<E>::push(const E& element) {
	if(this->t + 1 == this->capacity) throw StackFull("The stack is full");
	S[++t] = element;
}

template <typename E> void StackArray<E>::pop() {
	if(this->t == -1) throw StackEmpty("The stack is empty");
	t--;
}

int main(int argc, char const *argv[]) {
	StackArray<int>* a = new StackArray<int>(100);

	try {
		for(auto i = 0; i < 10; i++) {
			a->push(i + 5);
		}

		std::cout << a->top() << std::endl;
		a->pop();
		a->pop();
		a->pop();
		std::cout << a->top() << std::endl;
	}
	catch(const StackEmpty& e) {
		std::cout << e.getMessage() << std::endl;
	}
	catch(const StackFull& e) {
		std::cout << e.getMessage() << std::endl;
	}

	return 0;
}