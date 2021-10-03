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
    void addLast(const E& element);
    void removeLast();
    void swap(const Position& p , const Position& q);
};

template <typename E> CompleteBinaryTree<E>::CompleteBinaryTree() : V(1) {
    
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::pos(int i) {
    return V.begin() + i;
}

template <typename E> int CompleteBinaryTree<E>::idx(const Position& p) const {
    return p - V.begin();
}

template <typename E> int CompleteBinaryTree<E>::size() const {
    return this->V.size() - 1;
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::left(const Position& p) {
    return this->pos(2 * this->idx(p));
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::right(const Position& p) {
    return this->pos(2 * this->idx(p) + 1);
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::parent(const Position& p) {
    return this->pos((int)(this->idx(p) / 2));
}

template <typename E> bool CompleteBinaryTree<E>::hasLeft(const Position& p) const {
    return 2 * this->idx(p) <= this->size();
}

template <typename E> bool CompleteBinaryTree<E>::hasRight(const Position& p) const {
    return 2 * this->idx(p) + 1 <= this->size();
}

template <typename E> bool CompleteBinaryTree<E>::isRoot(const Position& p) const {
    return this->idx(p) == 1;
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::root() {
    return this->pos(1);
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::last() {
    return this->pos(this->size());
}

template <typename E> void CompleteBinaryTree<E>::addLast(const E& element) {
    this->V.push_back(element);
}

template <typename E> void CompleteBinaryTree<E>::removeLast() {
    this->V.pop_back();
}

template <typename E> void CompleteBinaryTree<E>::swap(const Position& p , const Position& q) {
    E temp = *p;
    *p = *q;
    *q = temp;
}

template <typename E , typename C> class MaxHeap {
private:
    CompleteBinaryTree<E> T;
    C isLess;

public:
    typedef typename CompleteBinaryTree<E>::Position Position;

public:
    MaxHeap(C isLess);
    int size() const;
    bool isEmpty() const;
    const E& max();
    void insert(const E& element);
    void removeMax();
};

template <typename E , typename C> MaxHeap<E , C>::MaxHeap(C isLess) {
    this->isLess = isLess;
}

template <typename E ,typename C> int MaxHeap<E , C>::size() const {
    return this->T.size();
}

template <typename E , typename C> bool MaxHeap<E , C>::isEmpty() const {
    return T.size() == 0;
}

template <typename E , typename C> const E& MaxHeap<E , C>::max() {
    return *(this->T.root());
}

template <typename E , typename C> void MaxHeap<E , C>::insert(const E& element) {
    this->T.addLast(element);
    Position v = this->T.last();

    while(!T.isRoot(v)) {
        Position u = this->T.parent(v);

        if(!isLess(*u , *v)) break;
        this->T.swap(u , v);
        v = u;
    }
}

template <typename E , typename C> void MaxHeap<E , C>::removeMax() {
    if(this->size() == 1) {
        this->T.removeLast();
    }
    else {
        this->T.swap(this->T.root() , this->T.last());
        this->T.removeLast();
        Position u = this->T.root();

        while(this->T.hasLeft(u)) {
            Position v = this->T.left(u);

            if(this->T.hasRight(u) && !isLess(*(this->T.right(u)) , *v)) {
                v = this->T.right(u);
            }

            if(isLess(*u , *v)) {
                this->T.swap(u , v);
                u = v;
            }
            else {
                break;
            }
        }
    }
}

template <typename E> class IsLess {
public:
    bool operator()(const E& a , const E& b) const {
        return a < b;
    }
};

int main(int argc, char const *argv[]) {
    IsLess<int> isLess;
    MaxHeap<int , IsLess<int>> heap = MaxHeap<int , IsLess<int>>(isLess);

    int arr[] = { 10 , 3 , 5 , 2 , 8 , 9 , 4 , 7 , 6 , 1 };

    for(auto i = 0; i < 10; i++) {
        heap.insert(arr[i]);
        std::cout << heap.max() << " ";
    }

    std::cout << std::endl;

    for(auto i = 0; i < 10; i++) {
        auto temp = heap.max();
        arr[10 - i - 1] = temp;
        heap.removeMax();
    }

    for(auto i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}