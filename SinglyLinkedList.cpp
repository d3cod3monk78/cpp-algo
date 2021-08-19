#include <bits/stdc++.h>

template <typename E> class Node;
template <typename E> class SinglyLinkedList;

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

template <typename E> SinglyLinkedList<E>::SinglyLinkedList() : entries(0) , head(nullptr) , tail(nullptr) {
	
}

template <typename E> SinglyLinkedList<E>::~SinglyLinkedList() {}

template <typename E> int SinglyLinkedList<E>::size() const { return this->entries; }
template <typename E> bool SinglyLinkedList<E>::isEmpty() const { return this->entries == 0; }
template <typename E> const E& SinglyLinkedList<E>::first() const { return this->head->element; }
template <typename E> const E& SinglyLinkedList<E>::last() const { return this->tail->element; }

template <typename E> void SinglyLinkedList<E>::addFirst(const E& element) {
	Node<E>* temp = new Node<E>();
	temp->element = element;
	temp->next = this->head;
	this->head = temp;
	if(this->isEmpty()) this->tail = this->head;
	this->entries++;
}

template <typename E> void SinglyLinkedList<E>::addLast(const E& element) {
	if(this->isEmpty()) this->addFirst(element);
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
	Node<E>* temp = this->head;
	this->head = this->head->next;
	this->entrie--;
	if(this->isEmpty()) this->tail = nullptr;
	delete temp;
}

int main(int argc, char const *argv[]) {
	SinglyLinkedList<int>* a = new SinglyLinkedList<int>();

	for(auto i = 0; i < 10; i++) {
		a->addFirst(i + 1);
	}

	std::cout << a->first() << std::endl;
	return 0;
}