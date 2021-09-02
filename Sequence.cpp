#include <iostream>

template <typename E> class Sequence {
private:
	class Node {
	public:
		Node* prev;
		Node* next;
		E element;
	};

public:
	class Iterator {
	private:
		Node* v;
		Iterator(Node* u);

	public:
		~Iterator();
		const E& operator*() const;
		bool operator==(const Iterator& p) const;
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();
		Iterator& operator--();
		friend class Sequence<E>;
	};

private:
	Node* header;
	Node* tailer;
	int entries;

public:
	Sequence();
	~Sequence();
	int size() const;
	bool isEmpty() const;
	Iterator begin() const;
	Iterator end() const;
	void insertFront(const E& element);
	void insertBack(const E& element);
	void insert(const Iterator& p , const E& element);
	void eraseFront();
	void eraseBack();
	void erase(const Iterator& p);
	Iterator atIndex(int index) const;
	int indexOf(const Iterator& p) const;
};

template <typename E> Sequence<E>::Iterator::Iterator(Node* u) {
	this->v = u;
}

template <typename E> Sequence<E>::Iterator::~Iterator() {}

template <typename E> const E& Sequence<E>::Iterator::operator*() const {
	return this->v->element;
}

template <typename E> bool Sequence<E>::Iterator::operator==(const Iterator& p) const {
	return this->v == p.v;
}

template <typename E> bool Sequence<E>::Iterator::operator!=(const Iterator& p) const {
	return this->v != p.v;
}

template <typename E> typename Sequence<E>::Iterator& Sequence<E>::Iterator::operator++() {
	this->v = this->v->next;
	return *this;
}

template <typename E> typename Sequence<E>::Iterator& Sequence<E>::Iterator::operator--() {
	this->v = this->v->prev;
	return *this;
}


template <typename E> Sequence<E>::Sequence() {
	this->header = new Node();
	this->tailer = new Node();
	this->header->next = this->tailer;
	this->tailer->prev = this->header;
	this->entries = 0;
}

template <typename E> Sequence<E>::~Sequence() {
	while(!this->isEmpty()) this->eraseFront();
}

template <typename E> int Sequence<E>::size() const { return this->entries; }
template <typename E> bool Sequence<E>::isEmpty() const { return this->entries == 0; }

template <typename E> typename Sequence<E>::Iterator Sequence<E>::begin() const {
	return Iterator(this->header->next);
}

template <typename E> typename Sequence<E>::Iterator Sequence<E>::end() const {
	return Iterator(this->tailer);
}

template <typename E> void Sequence<E>::insertFront(const E& element) {
	this->insert(this->begin() , element);
}

template <typename E> void Sequence<E>::insertBack(const E& element) {
	this->insert(this->end() , element);
}

template <typename E> void Sequence<E>::insert(const Iterator& p , const E& element) {
	Node* successor = p.v;
	Node* predecessor = successor->prev;
	Node* temp = new Node();
	temp->element = element;
	temp->next = successor;
	successor->prev = temp;
	predecessor->next = temp;
	temp->prev = predecessor;
	this->entries++;
}

template <typename E> void Sequence<E>::eraseFront() {
	this->erase(this->begin());
}

template <typename E> void Sequence<E>::eraseBack() {
	this->erase(--this->end());
}

template <typename E> void Sequence<E>::erase(const Iterator& p) {
	if(this->isEmpty()) return;
	Node* temp = p.v;
	Node* predecessor = temp->prev;
	Node* successor = temp->next;
	this->entries--;
	delete temp;
}

template <typename E> typename Sequence<E>::Iterator Sequence<E>::atIndex(int index) const {
	Iterator ptr = this->begin();

	for(auto i = 1; i <= index; i++) {
		++ptr;
	}

	return ptr;
}

template <typename E> int Sequence<E>::indexOf(const Iterator& p) const {
	Iterator ptr = this->begin();
	int pos = 0;

	while(ptr != p) {
		++ptr;
		pos++;
	}

	return pos;
}

int main(int argc, char const *argv[]) {
	Sequence<int>* arr = new Sequence<int>();

	for(auto i = 0; i < 10; i++) {
		arr->insertFront(i + 1);
	}

	Sequence<int>::Iterator ptr = arr->begin();

	while(ptr != arr->end()) {
		auto index = arr->indexOf(ptr);
		std::cout << "arr[" << index << "]: " << *(arr->atIndex(index)) << std::endl;
		++ptr;
	}

	return 0;
}