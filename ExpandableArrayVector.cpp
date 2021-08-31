#include <iostream>
#include <string>
#include <exception>

#define MAX(a , b) ((a) > (b)) ? (a) : (b)

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

class OutOfRangeException : public Exceptions {
public:
	OutOfRangeException(const std::string& err) : Exceptions(err) {}
};

template <typename E> class ExpandableArrayVector {
private:
	E* Vector;
	int entries;
	int capacity;

public:
	ExpandableArrayVector(int cap = 100);
	~ExpandableArrayVector();
	int size() const;
	bool isEmpty() const;
	const E& at(int index) const;
	void set(int index , const E& element);
	void insert(int index , const E& element);
	void erase(int index);
	void reserve(int N);
};

template <typename E> ExpandableArrayVector<E>::ExpandableArrayVector(int cap) {
	this->capacity = cap;
	this->entries = 0;
	this->Vector = new E[this->capacity];
}

template <typename E> ExpandableArrayVector<E>::~ExpandableArrayVector() {
	delete [] Vector;
}

template <typename E> int ExpandableArrayVector<E>::size() const { return this->entries; }
template <typename E> bool ExpandableArrayVector<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& ExpandableArrayVector<E>::at(int index) const {
	if(index < 0 || index >= capacity) throw OutOfRangeException("Index is out of bounds");
	if(this->isEmpty()) throw EmptyVectorException("The vector is empty");
	return this->Vector[index];
}

template <typename E> void ExpandableArrayVector<E>::set(int index , const E& element) {
	if(index < 0 || index >= capacity) throw OutOfRangeException("Index is out of bounds");
	this->Vector[index] = element;
}

template <typename E> void ExpandableArrayVector<E>::erase(int index) {
	if(index < 0 || index >= capacity) throw OutOfRangeException("Index is out of bounds");
	if(this->isEmpty()) throw EmptyVectorException("The vector is empty");

	for(auto i = index + 1; i < this->entries; i++) {
		this->Vector[i - 1] = this->Vector[i];
	}
	this->entries--;
}

template <typename E> void ExpandableArrayVector<E>::reserve(int N) {
	if(this->capacity >= N) return;
	E* clone = new E[N];

	for(auto i = 0; i < this->entries; i++) {
		clone[i] = this->Vector[i];
	}

	if(this->Vector != nullptr) delete [] Vector;
	this->Vector = clone;
	this->capacity = N;
}

template <typename E> void ExpandableArrayVector<E>::insert(int index , const E& element) {
	if(index < 0) throw OutOfRangeException("Index is out of bounds");
	if(this->entries >= this->capacity) this->reserve(MAX(1 , capacity));

	for(auto i = entries - 1; i > index - 1; i--) {
		this->Vector[i + 1] = this->Vector[i];
	}

	this->Vector[index] = element;
	this->entries++;
}

int main(int argc, char const *argv[]) {
	ExpandableArrayVector<int>* arr = new ExpandableArrayVector<int>(10);

	for(auto i = 0; i < 11; i++) {
		arr->insert(i , i + 1);
	}

	for(auto i = 0; i < arr->size(); i++) {
		std::cout << arr->at(i) << std::endl;
	}

	return 0;
}