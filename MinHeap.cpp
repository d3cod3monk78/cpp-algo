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
    return this->V.begin() + i;
}

template <typename E> int CompleteBinaryTree<E>::idx(const Position& p) const {
    return p - this->V.begin();
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

template <typename E , typename C> class HeapPriorityQueue {
private:
    CompleteBinaryTree<E> T;
    C isLess;
    typedef typename CompleteBinaryTree<E>::Position Position;

public:
    HeapPriorityQueue(const C& isLess);
    int size() const;
    bool isEmpty() const;
    void insert(const E& element);
    const E& min();
    void removeMin();
};

template <typename E , typename C> HeapPriorityQueue<E , C>::HeapPriorityQueue(const C& isLess) {
    this->isLess = isLess;
}

template <typename E , typename C> int HeapPriorityQueue<E , C>::size() const {
    return this->T.size();
}

template <typename E , typename C> bool HeapPriorityQueue<E , C>::isEmpty() const {
    return this->size() == 0;
}

template <typename E , typename C> const E& HeapPriorityQueue<E , C>::min() {
    return *(T.root());
}

template <typename E , typename C> void HeapPriorityQueue<E , C>::insert(const E& element) {
    this->T.addLast(element);
    Position v = T.last();

    while(!T.isRoot(v)) {
        Position u = T.parent(v);

        if(!isLess(*v , *u)) break;
        T.swap(v , u);
        v = u;
    }
}

template <typename E , typename C> void HeapPriorityQueue<E , C>::removeMin() {
    if(this->size() == 1) {
        this->T.removeLast();
    }
    else {
        T.swap(this->T.root() , this->T.last());
        this->T.removeLast();
        Position u = this->T.root();

        while(this->T.hasLeft(u)) {
            Position v = this->T.left(u);

            if(this->T.hasRight(u) && *(this->T.right(u)) < *v) {
                v = this->T.right(u);
            }

            if(isLess(*v , *u)) {
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
    bool operator()(const E& a , const E& b) {
        return a < b;
    }
};

int main(int argc, char const *argv[]) {
    IsLess<int> isLess;
    HeapPriorityQueue<int , IsLess<int>> heap = HeapPriorityQueue<int , IsLess<int>>(isLess);

    int arr[] = { 10 , 3 , 5 , 2 , 8 , 9 , 4 , 7 , 6 , 1 };

    for(auto i = 0; i < 10; i++) {
        heap.insert(arr[i]);
        std::cout << heap.min() << " ";
    }

    std::cout << std::endl;

    for(auto i = 0; i < 10; i++) {
        auto temp = heap.min();
        arr[i] = temp;
        heap.removeMin();
    }

    for(auto i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;


    return 0;
}