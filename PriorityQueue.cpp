#include <iostream>
#include <list>

template <typename E , typename C> class PriorityQueue {
private:
    std::list<E>* L;
    C isLess;

public:
    PriorityQueue(const C& isLess);
    ~PriorityQueue();
    int size() const;
    bool isEmpty() const;
    void insert(const E& element);
    const E& min() const;
    void removeMin();
};

template <typename E , typename C> PriorityQueue<E , C>::PriorityQueue(const C& isLess) {
    this->isLess = isLess;
    L = new std::list<E>();
}

template <typename E , typename C> PriorityQueue<E , C>::~PriorityQueue() {
    L->clear();
    delete L;
}

template <typename E , typename C> int PriorityQueue<E , C>::size() const { return this->L->size(); }

template <typename E , typename C> bool PriorityQueue<E , C>::isEmpty() const { return this->L->empty(); }

template <typename E , typename C> void PriorityQueue<E , C>::insert(const E& element) {
    typename std::list<E>::iterator p; 
    p = this->L->begin();

    while(p != this->L->end() && !isLess(element , *p)) {
        ++p;
    }
    L->insert(p , element);
}

template <typename E , typename C> const E& PriorityQueue<E , C>::min() const {
    return L->front();
}

template <typename E , typename C> void PriorityQueue<E , C>::removeMin() { L->pop_front(); }

class IsLess {
public:
    bool operator()(int x , int y);
};

bool IsLess::operator()(int x , int y) {
    return x < y;
}

int main(int argc, char const *argv[]) {
    IsLess isLess;
    PriorityQueue<int , IsLess>* queue = new PriorityQueue<int , IsLess>(isLess);

    queue->insert(10);
    queue->insert(1);
    queue->insert(5);
    queue->insert(3);

    std::cout << queue->min() << std::endl;
    queue->removeMin();
    std::cout << queue->min() << std::endl;
    queue->removeMin();
    std::cout << queue->min() << std::endl;
    queue->removeMin();
    delete queue;

    return 0;
}