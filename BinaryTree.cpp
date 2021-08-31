#include <bits/stdc++.h>
#include <list>

template <typename E> class BinaryTree {
protected:
	class Node {
	public:
		E element;
		Node* parent;
		Node* left;
		Node* right;
		Node();
	};

public:
	class Position {
	private:
		Node* v;

	public:
		Position(Node* u = nullptr);
		E& operator*() const;
		Position& left() const;
		Position& right() const;
		Position& parent() const;
		bool isRoot() const;
		bool isExternal() const;
		friend class BinaryTree<E>;
	};
	typedef std::list<Position> PositionList;

protected:
	void preorder(Node* v , PositionList& pl) const;

private:
	Node* rootNode;
	int entries;

public:
	BinaryTree();
	int size() const;
	bool isEmpty() const;
	Position& root() const;
	PositionList& positions() const;
	void addRoot();
	void expandExternal(const Position& p);
	Position& removeAboveExternal(const Position& p);
};

template <typename E> BinaryTree<E>::Node::Node() {
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

template <typename E> BinaryTree<E>::Position::Position(Node* u) {
	this->v = u;
}

template <typename E> E& BinaryTree<E>::Position::operator*() const { return this->v->element; }
template <typename E> typename BinaryTree<E>::Position& BinaryTree<E>::Position::left() const { return Position(this->v->left); }
template <typename E> typename BinaryTree<E>::Position& BinaryTree<E>::Position::right() const { return Position(this->v->right); }
template <typename E> typename BinaryTree<E>::Position& BinaryTree<E>::Position::parent() const { return Position(this->v->parent); }
template <typename E> bool BinaryTree<E>::Position::isRoot() const { return this->v->parent != nullptr; }
template <typename E> bool BinaryTree<E>::Position::isExternal() const { return (this->v->left == nullptr && this->v->right == nullptr); }

template <typename E> BinaryTree<E>::BinaryTree() {
	this->rootNode = nullptr;
	this->entries = 0;
}

template <typename E> int BinaryTree<E>::size() const { return this->entries; }
template <typename E> bool BinaryTree<E>::isEmpty() const { return this->entries == 0; }
template <typename E> typename BinaryTree<E>::Position& BinaryTree<E>::root() const { return Position(this->rootNode); }
template <typename E> void BinaryTree<E>::addRoot() {
	this->rootNode = new Node();
	this->entries++;
}

template <typename E> void BinaryTree<E>::expandExternal(const Position& p) {
	Node* v = p.v;
	v->left = new Node();
	v->left->parent = v;
	v->right = new Node();
	v->right->parent = v;
	this->entries += 2;
}

template <typename E> typename BinaryTree<E>::Position& BinaryTree<E>::removeAboveExternal(const Position& p) {
	Node* node = p.v;
	Node* parent = node->parent;
	Node* sibling = (node == parent->left) ? parent->right : parent->left;

	if(parent == rootNode) {
		rootNode = sibling;
		sibling->parent = nullptr;
	}
	else {
		Node* grandParent = parent->parent;
		if(parent == grandParent->left) {
			grandParent->left = sibling;
		}
		else {
			grandParent->right = sibling;
		}
		sibling->parent = grandParent;
	}

	delete node;
	delete parent;
	this->entries -= 2;
	return Position(sibling);
}

template <typename E> typename BinaryTree<E>::PositionList BinaryTree<E>::positions() const {
	PositionList pl;
	preorder(rootNode , pl);
	return PositionList;
}

template <typename E> void BinaryTree<E>::preorder(Node* v , PositionList& pl) const {
	pl.push_back(Position(v));
	if(v->left != nullptr) {
		preorder(v->left , pl);
	}
	else if(v->right != nullptr){
		preorder(v->right , pl);
	}
}