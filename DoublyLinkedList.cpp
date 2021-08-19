#include <bits/stdc++.h>

template <typename E> class Node;
template <typename E> class DoublyLinkedList;

template <typename E> class Node {
	E element;
	Node<E>* next;
	Node<E>* prev;
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
	void removeBetween(Node<E>* node);
};

template <typename E> DoublyLinkedList<E>::DoublyLinkedList() : entries(0) {
	entries = 0;
	header = new Node<E>();
	tailer = new Node<E>();
	header->next = tailer;
	tailer->prev = header;
}

template <typename E> DoublyLinkedList<E>::~DoublyLinkedList() {}

template <typename E> int DoublyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool DoublyLinkedList<E>::isEmpty() const { return this->entries == 0; }
template <typename E> const E& DoublyLinkedList<E>::first() const { return this->header->next->element; }
template <typename E> const E& DoublyLinkedList<E>::last() const { return this->tailer->prev->element; }

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

template <typename E> void DoublyLinkedList<E>::removeFirst() { this->removeBetween(this->header->next); }
template <typename E> void DoublyLinkedList<E>::removeLast() { this->removeBetween(this->tailer->prev); }

template <typename E> void DoublyLinkedList<E>::removeBetween(Node<E>* node) {
	Node<E>* predecessor = node->prev;
	Node<E>* successor = node->next;
	predecessor->next = successor;
	successor->prev = predecessor;
	this->entries--;
	delete node;
}

int main(int argc, char const *argv[]) {
	DoublyLinkedList<int>* a = new DoublyLinkedList<int>();

	for(auto i = 0; i < 10; i++) {
		a->addFirst(i + 1);
	}

	std::cout << a->first() << std::endl;
	return 0;
}