#include <iostream>
#include <iostream>

template <typename E> class BinaryTree {
protected:
    class Node {
    public:
        E element;
        Node* parent;
        Node* leftChild;
        Node* rightChild;
        Node();
    };

public:
    class Position {
    private:
        Node* v;

    public:
        Position(Node* u);
        const E& operator*() const;
        Position left() const;
        Position right() const;
        Position parent() const;
        bool isRoot() const;
        bool isExternal() const;
        friend class BinaryTree<E>;
    };

public:
    typedef std::list<Position> PositionList;

private:
    Node* rootNode;
    int entries;

protected:
    void preorder(Node* v , PositionList& pl);

public:
    BinaryTree();
    int size() const;
    bool isEmpty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
};

template <typename E> BinaryTree<E>::Node::Node() {
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <typename E> BinaryTree<E>::Position::Position(Node* u) {
    this->v = u;
}

template <typename E> const E& BinaryTree<E>::Position::operator*() const {
    return this->v->element;
}

template <typename E> typename BinaryTree<E>::Position BinaryTree<E>::Position::left() const {
    return Position(this->v->leftChild);
}

template <typename E> typename BinaryTree<E>::Position BinaryTree<E>::Position::right() const {
    return Position(this->v->rightChild);
}

template <typename E> typename BinaryTree<E>::Position BinaryTree<E>::Position::parent() const {
    return Position(this->v->parent);
}

template <typename E> bool BinaryTree<E>::Position::isRoot() const {
    return this->v->parent == nullptr;
}

template <typename E> bool BinaryTree<E>::Position::isExternal() const {
    return this->v->leftChild == nullptr && this->v->rightChild == nullptr;
}

template <typename E> BinaryTree<E>::BinaryTree() {
    this->rootNode = nullptr;
    this->entries = 0;
}

template <typename E> int BinaryTree<E>::size() const { return this->entries; }

template <typename E> bool BinaryTree<E>::isEmpty() const { return this->entries == 0; }

template <typename E> typename BinaryTree<E>::Position root() const {
    return Position(this->rootNode);
}

template <typename E> typename BinaryTree<E>::PositionList BinaryTree<E>::position() {
    PositionList pl;
    this->preorder(this->rootNode , pl);
    return PositionList(pl);
}

template <typename E> void BinaryTree<E>::addRoot() {
    this->rootNode = new Node();
    this->entries = 1;
}

template <typename E> void BinaryTree<E>::expandExternal(const Position& p) {
    Node* v = p.v;
    v->leftChild = new Node();
    v->leftChild->parent = v;
    v->right = new Node();
    v->right->parent = v;
    this->entries += 2;
}

template <typename E> typename BinaryTree<E>::Position BinaryTree<E>::removeAboveExternal(const Position& p) {
    Node* child = p.v;
    Node* parentNode = child->parent;
    Node* sibling = (parantNode->leftChild == child) ? parentNode->rightChild : parentNode->leftChild;

    if(parent == this->rootNode) {
        this->rootNode = sibling;
        sibling->parent = nullptr;
    }
    else {
        Node* grandParent = parentNode->parent;
        if(grandParent->leftChild == parentNode) grandParent->leftChild = sibling;
        else grandParent->rightChild = sibling;
        sibling->parent = grandParent;
    }

    delete child;
    delete parentNode;
    this->entries -= 2;
    return Position(sibling);
}

template <typename E> void BinaryTree<E>::preorder(Node* v , PositionList& pl) {
    pl.push_back(Position(v));
    if(v->leftChild != nullptr) {
        preorder(v->leftChild , pl);
    }
    if(v->rightChild != nullptr) {
        preorder(v->rightChild , pl);
    }
}