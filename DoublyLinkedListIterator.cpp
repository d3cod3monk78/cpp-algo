#include <bits/stdc++.h>

template <typename E> class DoublyLinkedListIterator {
private:
	class Node {
	public:
		E element;
		Node* prev;
		Node* next;
	};

public:
	class Iterator {
	private:
		Node* v;
		Iterator(Node* u);

	public:
		E& operator*();
		bool operator==(const Iterator& p) const;
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();
		Iterator& operator--();
		friend class DoublyLinkedListIterator<E>;
	};

private:
	int entries;
	Node* header;
	Node* tailer;

public:
	DoublyLinkedListIterator();
	~DoublyLinkedListIterator();
	int size() const;
	bool isEmpty() const;
	Iterator begin() const;
	Iterator end() const;
	const E& first() const;
	void insertFront(const E& element);
	void insertBack(const E& element);
	void insert(const Iterator& p , const E& element);
	void eraseFront();
	void eraseBack();
	void erase(const Iterator& p);
};

template <typename E> DoublyLinkedListIterator<E>::Iterator::Iterator(Node* u) {
	this->v = u;
}

template <typename E> E& DoublyLinkedListIterator<E>::Iterator::operator*() { return this->v->element; }
template <typename E> bool DoublyLinkedListIterator<E>::Iterator::operator==(const Iterator& p) const {
	return this->v == p.v;
}

template <typename E> bool DoublyLinkedListIterator<E>::Iterator::operator!=(const Iterator& p) const {
	return this->v != p.v;
}

template <typename E> typename DoublyLinkedListIterator<E>::Iterator& DoublyLinkedListIterator<E>::Iterator::operator++() {
	this->v = this->v->next;
	return *this;
}

template <typename E> typename DoublyLinkedListIterator<E>::Iterator& DoublyLinkedListIterator<E>::Iterator::operator--() {
	this->v = this->v->prev;
	return *this;
}

template <typename E> DoublyLinkedListIterator<E>::DoublyLinkedListIterator() {
	this->entries = 0;
	this->header = new Node();
	this->tailer = new Node();
	this->header->next = this->tailer;
	this->tailer->prev = this->header;
}

template <typename E> DoublyLinkedListIterator<E>::~DoublyLinkedListIterator() {
	while(!this->isEmpty()) this->eraseFront();
}

template <typename E> typename DoublyLinkedListIterator<E>::Iterator DoublyLinkedListIterator<E>::begin() const {
	return Iterator(this->header->next);
}

template <typename E> typename DoublyLinkedListIterator<E>::Iterator DoublyLinkedListIterator<E>::end() const {
	return Iterator(this->tailer);
}

template <typename E> const E& DoublyLinkedListIterator<E>::first() const {
	return *(this->begin());
}

template <typename E> void DoublyLinkedListIterator<E>::insertFront(const E& element) {
	this->insert(this->begin() , element);
}

template <typename E> void DoublyLinkedListIterator<E>::insertBack(const E& element) {
	this->insert(this->end() , element);
}

template <typename E> void DoublyLinkedListIterator<E>::insert(const Iterator& p , const E& element) {
	Node* successor = p.v;
	Node* predecessor = p.v->prev;
	Node* temp = new Node();
	temp->element = element;
	temp->next = successor;
	successor->prev = temp;
	temp->prev = predecessor;
	predecessor->next = temp;
	this->entries++;
}

template <typename E> void DoublyLinkedListIterator<E>::eraseFront() {
	this->erase(this->begin());
}

template <typename E> void DoublyLinkedListIterator<E>::eraseBack() {
	this->erase(--(this->end()));
}

template <typename E> void DoublyLinkedListIterator<E>::erase(const Iterator& p) {
	Node* predecessor = p.v->prev;
	Node* successor = p.v->next;
	predecessor->next = successor;
	successor->prev = predecessor;
	delete p.v;
	this->entries--;
}

int main(int argc, char const *argv[]) {
	DoublyLinkedListIterator<int>* a = new DoublyLinkedListIterator<int>();

	for(auto i = 0; i < 10; i++) {
		a->insertFront(i + 5);
	}

	DoublyLinkedListIterator<int>::Iterator ptr = a->begin();
	while(ptr != a->end()) {
		std::cout << *ptr << std::endl;
		++ptr;
	}
	
	return 0;
}