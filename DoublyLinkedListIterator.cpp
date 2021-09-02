#include <iostream>

template <typename E> class DoublyLinkedListIterator {
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
		friend class DoublyLinkedListIterator<E>;
	};

private:
	Node* header;
	Node* tailer;
	int entries;

public:
	DoublyLinkedListIterator();
	~DoublyLinkedListIterator();
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
};

template <typename E> DoublyLinkedListIterator<E>::Iterator::Iterator(Node* u) {
	this->v = u;
}

template <typename E> DoublyLinkedListIterator<E>::Iterator::~Iterator() {}

template <typename E> const E& DoublyLinkedListIterator<E>::Iterator::operator*() const {
	return this->v->element;
}

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
	this->header = new Node();
	this->tailer = new Node();
	this->header->next = this->tailer;
	this->tailer->prev = this->header;
	this->entries = 0;
}

template <typename E> DoublyLinkedListIterator<E>::~DoublyLinkedListIterator() {
	while(!this->isEmpty())
		this->eraseFront();
}

template <typename E> int DoublyLinkedListIterator<E>::size() const { return this->entries; }
template <typename E> bool DoublyLinkedListIterator<E>::isEmpty() const { return this->entries == 0; }

template <typename E> typename DoublyLinkedListIterator<E>::Iterator DoublyLinkedListIterator<E>::begin() const {
	return Iterator(this->header->next);
}

template <typename E> typename DoublyLinkedListIterator<E>::Iterator DoublyLinkedListIterator<E>::end() const {
	return Iterator(this->tailer);
}

template <typename E> void DoublyLinkedListIterator<E>::insertFront(const E& element) {
	this->insert(this->begin() , element);
}

template <typename E> void DoublyLinkedListIterator<E>::insertBack(const E& element) {
	this->insert(this->end() , element);
}

template <typename E> void DoublyLinkedListIterator<E>::insert(const Iterator& p , const E& element) {
	Node* successor = p.v;
	Node* predecessor = successor->prev;
	Node* temp = new Node();
	temp->element = element;
	predecessor->next = temp;
	temp->prev = predecessor;
	successor->prev = temp;
	temp->next = successor;
	this->entries++;
}

template <typename E> void DoublyLinkedListIterator<E>::eraseFront() {
	this->erase(this->begin());
}

template <typename E> void DoublyLinkedListIterator<E>::eraseBack() {
	this->erase(--this->end());
}

template <typename E> void DoublyLinkedListIterator<E>::erase(const Iterator& p) {
	if(this->isEmpty()) return;
	Node* temp = p.v;
	Node* successor = temp->next;
	Node* predecessor = temp->prev;
	successor->prev = predecessor;
	predecessor->next = successor;
	this->entries--;
	delete temp;
}

int main(int argc, char const *argv[]) {
	
	DoublyLinkedListIterator<int>* arr = new DoublyLinkedListIterator<int>();

	for(auto i = 0; i < 10; i++) {
		arr->insertFront(i + 1);
	}

	DoublyLinkedListIterator<int>::Iterator ptr = arr->begin();

	while(ptr != arr->end()) {
		std::cout << *ptr << std::endl;
		++ptr;
	}

	return 0;
}