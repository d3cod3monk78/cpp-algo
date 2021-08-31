#include <bits/stdc++.h>

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
}