#include <iostream>
#include <vector>
#include <iterator>

template <typename E> class CompleteBinaryTree {
private:
    std::vector<E> V;

public:
    typedef typename std::vector<E>::iterator Position;

protected:
    Position pos(int i);
    int idx(const Position& p) const;

public:
    CompleteBinaryTree();
    int size() const;
    Position left(const Position& p);
    Position right(const Position& p);
    Position parent(const Position& p);
    bool hasLeft(const Position& p) const;
    bool hasRight(const Position& p) const;
    bool isRoot(const Position& p) const;
    Position root();
    Position last();
    void addLast(const E& e);
    void removeLast();
    void swap(const Position& p , const Position& q);
};

template <typename E> CompleteBinaryTree<E>::Comparator() : V(1) {
    
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::pos(int i) {
    return V.begin() + i;
}

template <typename E> int CompleteBinaryTree<E>::idx(const Position& p) const {
    return p - V.begin();
}

template <typename E> int CompleteBinaryTree<E>::size() const { return V.size() - 1; }

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::left(const Position& p) {
    return pos(2 * idx(p));
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::right(const Position& p) {
    return pos(2 * idx(p) + 1);
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::parent(const Position& p) {
    return pos(idx(p) / 2);
}

template <typename E> bool CompleteBinaryTree<E>::hasLeft(const Position& p) const {
    return 2 * idx(p) <= this->size();
}

template <typename E> bool CompleteBinaryTree<E>::hasRight(const Position& p) const {
    return 2 * idx(p) + 1 <= this->size();
}

template <typename E> bool CompleteBinaryTree<E>::isRoot(const Position& p) const {
    return idx(p) == 1;
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::root() {
    return pos(1);
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::last() {
    return pos(this->size());
}

template <typename E> void CompleteBinaryTree<E>::addLast(const E& element) {
    V.push_back(element);
}

template <typename E> void CompleteBinaryTree<E>::removeLast() {
    V.pop_back();
}

template <typename E> void CompleteBinaryTree<E>::swap(const Position& p , const Position& q) {
    E element = *q;
    *q = *p;
    *p = e;
}