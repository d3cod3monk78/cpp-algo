// Pattern Matching Algorithm
/*#include <iostream>
#include <vector>
#include <string>

template <typename E> class Node;
template <typename E> class Stack;

template <typename E> class Node {
    Node<E>* next;
    E element;
    friend class Stack<E>;
};

template <typename E> class Stack {
private:
    Node<E>* head;
    Node<E>* tail;
    int entries;

public:
    Stack();
    ~Stack();
    int size() const;
    bool isEmpty() const;
    const E& top() const;
    const E& back() const;
    void push(const E& element);
    void pop();
};

template <typename E> Stack<E>::Stack() {
    this->entries = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename E> Stack<E>::~Stack() {
    while(!this->isEmpty()) this->pop();
}

template <typename E> int Stack<E>::size() const { return this->entries; }
template <typename E> bool Stack<E>::isEmpty() const { return this->entries == 0; }

template <typename E> const E& Stack<E>::top() const { return this->head->element; }
template <typename E> const E& Stack<E>::back() const { return this->tail->element; }

template <typename E> void Stack<E>::push(const E& element) {
    Node<E>* temp = new Node<E>();
    temp->element = element;

    temp->next = this->head;
    this->head = temp;
    if(this->isEmpty()) this->tail = this->head;
    this->entries++;
}

template <typename E> void Stack<E>::pop() {
    Node<E>* temp = this->head;
    this->head = this->head->next;
    this->entries--;
    if(this->isEmpty()) this->tail = nullptr;
    delete temp;
}

char getValidBracket(const char& bracket) {
    if(bracket == '(') return ')';
    else if(bracket == '[') return ']';
    else return '}';
}

bool isMatch(std::string& pattern) {
    Stack<char>* arr = new Stack<char>();

    for(auto i = 0; i < (int)pattern.size(); i++) {
        if((char)pattern[i] == '(' || (char)pattern[i] == '[' || (char)pattern[i] == '{') {
            arr->push(pattern[i]);
        }
        else if((char)pattern[i] == ')' || (char)pattern[i] == ']' || (char)pattern[i] == '}') {
            if(arr->isEmpty()) return false;
            if(getValidBracket(arr->top()) != (char)pattern[i]) return false;
            arr->pop();
        }
    }

    if(arr->isEmpty()) {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    std::string pattern;
    getline(std::cin , pattern);
    std::cout << pattern << std::endl;
    if(isMatch(pattern)) {
        std::cout << "Pattern is valid" << std::endl;
    }
    else {
        std::cout << "Pattern is not valid" << std::endl;        
    }
    return 0;
}*/


/*#include <iostream>
#include <stack>
#include <string>

bool isValid(const string& pattern) {
    std::stack<char>* arr = new std::stack<char>();

    for(auto i = 0; i < (int)pattern.size(); i++) {
        if(
            (char)pattern[i] != '(' 
            && (char)pattern[i] != ')'
            && (char)pattern[i] != '['
            && (char)pattern[i] != ']'
            && (char)pattern[i] != '{'
            && (char)pattern[i] != '}') {
            continue;
        }
        else if(
            (char)pattern[i] == '(' ||
            (char)pattern[i] == '[' ||
            (char)pattern[i] == '{'
            ) {
            arr->push((char)pattern[i]);
        }
        else if(
            (char)pattern[i] == ')' ||
            (char)pattern[i] == ']' ||
            (char)pattern[i] == '}' ||
            ) {
            if(arr->empty()) return false;
            if(
                ((char)pattern[i] == ')' && arr->top() == '(') ||
                ((char)pattern[i] == ']' && arr->top() == '[') ||
                ((char)pattern[i] == '}' && arr->top() == '{') 
                ) {
                arr->pop();
            }
            else {
                return false;
            }
        }
    }

    if(arr->empty()) return true;
    return false;
}

std::string getPostfix(const std::string& pattern) {
    
}

int main(int argc, char const *argv[]) {
    
    std::string pattern;
    getline(std::cin , pattern);

    if(!isValid(pattern)) {
        std::cout << "This pattern is not valid to solve" << std::endl;
    }
    else {

    }

    return 0;
}*/

/*#include <iostream>
#include <stack>
#include <string>


bool checkIsValidExpression(const std::string& pattern) {
    std::stack<char>* arr = new std::stack<char>();
    const auto patternSize = (int)pattern.size();

    for(auto i = 0; i < patternSize; i++) {
        if(
            (char)pattern[i] != '(' &&
            (char)pattern[i] != ')' &&
            (char)pattern[i] != '[' &&
            (char)pattern[i] != ']' &&
            (char)pattern[i] != '{' &&
            (char)pattern[i] != '}'
            ) {
            continue;
        }
        else {
            if(
                (char)pattern[i] == '(' ||
                (char)pattern[i] == '[' ||
                (char)pattern[i] == '{'
                ) {
                arr->push((char)pattern[i]);
            }
            else if(
                (char)pattern[i] == ')' ||
                (char)pattern[i] == ']' ||
                (char)pattern[i] == '}'
                ) {

                if(arr->empty()) return false;
                else {
                    if(
                        ((char)pattern[i] == ')' && arr->top() == '(') ||
                        ((char)pattern[i] == ']' && arr->top() == '[') ||
                        ((char)pattern[i] == '}' && arr->top() == '{')
                        ) {
                        arr->pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }

    if(arr->empty()) {
        return true;
    }

    return false;
}

int getOperatorPrecedence(const char& op) {
    if(op == '^') {
        return 2;
    }
    else if(op == '*' || op == '/') {
        return 1;
    } else {
        return 0;
    }
}

std::string getPostfixPattern(const std::string& pattern) {
    std::string postfixPattern;
    std::stack<char>* operatorArray = new std::stack<char>();
    const int patternSize = (int)pattern.size();

    for(auto i = 0; i < patternSize; i++) {
        if(
            (char)pattern[i] != '(' &&
            (char)pattern[i] != ')' &&
            (char)pattern[i] != '[' &&
            (char)pattern[i] != ']' &&
            (char)pattern[i] != '{' &&
            (char)pattern[i] != '}' &&
            (char)pattern[i] != '^' &&
            (char)pattern[i] != '*' &&
            (char)pattern[i] != '/' &&
            (char)pattern[i] != '+' &&
            (char)pattern[i] != '-'
            ) {
            postfixPattern.push_back((char)pattern[i]);
        } else {
            if(
                (char)pattern[i] == '(' ||
                (char)pattern[i] == '[' ||
                (char)pattern[i] == '{'
                ) {
                operatorArray->push(pattern[i]);
            } else if(
                (char)pattern[i] == ')' ||
                (char)pattern[i] == ']' ||
                (char)pattern[i] == '}'
                ) {
                while(
                    operatorArray->top() != '(' &&
                    operatorArray->top() != '[' &&
                    operatorArray->top() != '{'
                    ) {
                    postfixPattern.push_back(operatorArray->top());
                    operatorArray->pop();
                }
                operatorArray->pop();
            } else if(
                operatorArray->empty() ||
                operatorArray->top() == '(' ||
                operatorArray->top() == '[' ||
                operatorArray->top() == '{'
                ) {
                operatorArray->push((char)pattern[i]);       
            } else {
                if(getOperatorPrecedence((char)pattern[i]) > getOperatorPrecedence(operatorArray->top())) {
                    operatorArray->push((char)pattern[i]);
                } else {
                    if(getOperatorPrecedence((char)pattern[i]) < getOperatorPrecedence(operatorArray->top())) {
                        while(getOperatorPrecedence((char)pattern[i]) < getOperatorPrecedence(operatorArray->top())) {
                            postfixPattern.push_back(operatorArray->top());
                            operatorArray->pop();
                            if(operatorArray->empty()) {
                                goto outerLowerPrecedence;
                            }
                        }

                        outerLowerPrecedence:;
                    } 
                    if(getOperatorPrecedence((char)pattern[i]) == getOperatorPrecedence(operatorArray->top())) {
                        while(getOperatorPrecedence((char)pattern[i]) == getOperatorPrecedence(operatorArray->top())) {
                            postfixPattern.push_back(operatorArray->top());
                            operatorArray->pop();
                            if(operatorArray->empty()) {
                                goto outerSamePrecedence;
                            }
                        }

                        outerSamePrecedence:;
                    }

                    operatorArray->push((char)pattern[i]);
                }
            }
        }
    }

    while(!operatorArray->empty()) {
        postfixPattern.push_back(operatorArray->top());
        operatorArray->pop();
    }

    return postfixPattern;
}



int main(int argc, char const *argv[]) {
    std::string pattern;
    getline(std::cin , pattern);

    if(checkIsValidExpression(pattern)) {
        std::cout << "This expression is a valid expression" << std::endl;
        std::cout << getPostfixPattern(pattern) << std::endl;
    }
    else {
        std::cout << "This expression is a not valid expression" << std::endl;
    }
    return 0;
}*/

/*#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <fstream>

#define ABS_DIFFERENCE(a , b) ((a) > (b) ? (a) - (b) : (b) - (a))

class RomanNumberConverter {
private:
    const unsigned char ONE = 'I';
    const unsigned char FIVE = 'V';
    const unsigned char TEN = 'X';
    const unsigned char FIFTY = 'L';
    const unsigned char HUNDRED = 'C';
    const unsigned char FIVE_HUNDRED = 'D';
    const unsigned char THOUSAND = 'M';

private:
    enum {
        VALUE_OF_ONE = 1 ,
        VALUE_OF_FIVE = 5 ,
        VALUE_OF_TEN = 10 ,
        VALUE_OF_FIFTY = 50 ,
        VALUE_OF_HUNDRED = 100 ,
        VALUE_OF_FIVE_HUNDRED = 500 ,
        VALUE_OF_THOUSAND = 1000
    };

private:
    bool checkIsValidExpression(const std::string& pattern) const;
    bool checkIsValidLetter(const unsigned char& letter) const;
    int getValueOfLetter(const unsigned char& letter) const;
    bool checkIsMatchPairs(const unsigned char& predecessor , const unsigned char& successor) const;
    int generateResult(std::stack<unsigned char>*& letterStack);

public:
    RomanNumberConverter();
    ~RomanNumberConverter();
    void init();
};

RomanNumberConverter::RomanNumberConverter() {
    
}

RomanNumberConverter::~RomanNumberConverter() {
}

int RomanNumberConverter::getValueOfLetter(const unsigned char& letter) const {
    if(letter == ONE) {
        return VALUE_OF_ONE;
    } else if(letter == FIVE) {
        return VALUE_OF_FIVE;
    }
    else if(letter == TEN) {
        return VALUE_OF_TEN;
    }
    else if(letter == FIFTY) {
        return VALUE_OF_FIFTY;
    }
    else if(letter == HUNDRED) {
        return VALUE_OF_HUNDRED;
    }
    else if(letter == FIVE_HUNDRED) {
        return VALUE_OF_FIVE_HUNDRED;
    }
    else {
        return VALUE_OF_THOUSAND;
    }
}

bool RomanNumberConverter::checkIsValidLetter(const unsigned char& letter) const {
    if(
        letter != this->ONE &&
        letter != this->FIVE &&
        letter != this->TEN &&
        letter != this->FIFTY &&
        letter != this->HUNDRED &&
        letter != this->FIVE_HUNDRED &&
        letter != this->THOUSAND
        ) {
        return false;
    }
    return true;
}

bool RomanNumberConverter::checkIsMatchPairs(const unsigned char& predecessor , const unsigned char& successor) const {
    if(predecessor == ONE) {
        if(successor == FIVE || successor == TEN) {
            return true;
        }
    }
    else if(predecessor == TEN) {
        if(successor == FIFTY || successor == HUNDRED) {
            return true;
        }
    }
    else if(predecessor == HUNDRED) {
        if(successor == FIVE_HUNDRED || successor == THOUSAND) {
            return true;
        }
    }

    return false;
}

bool RomanNumberConverter::checkIsValidExpression(const std::string& pattern) const {
    const auto patternSize = (int)pattern.size();

    for(auto i = 0; i < patternSize - 3; i++) {
        if(!this->checkIsValidLetter((unsigned char)pattern[i])) {
            return false;
        }
        else {
            if(
                (unsigned char)pattern[i] == (unsigned char)pattern[i + 1] && 
                (unsigned char)pattern[i] == (unsigned char)pattern[i + 2]
                ) {
                return false;
            }
            else if(
                getValueOfLetter((unsigned char)pattern[i]) < 
                getValueOfLetter((unsigned char)pattern[i + 1])
                ) {
                if(
                    getValueOfLetter((unsigned char)pattern[i]) <=
                    getValueOfLetter((unsigned char)pattern[i + 2])
                    ) {
                    return false;
                } else if(!checkIsMatchPairs(pattern[i] , pattern[i + 1])) {
                    return false;
                }
            }
        }
    }

    for(auto i = patternSize - 3; i < patternSize; i++) {
        if(!this->checkIsValidLetter(pattern[i])) return false;
    }

    for(auto i = patternSize - 3; i < patternSize - 1; i++) {
        if(
            getValueOfLetter((unsigned char)pattern[i]) < 
            getValueOfLetter((unsigned char)pattern[i + 1])
            ) {
             if(!checkIsMatchPairs(pattern[i] , pattern[i + 1])) {
                return false;
            }
        }
    }

    if(
        getValueOfLetter((unsigned char)pattern[patternSize - 3]) < 
        getValueOfLetter((unsigned char)pattern[patternSize - 2])
        ) {
        if(
            getValueOfLetter((unsigned char)pattern[patternSize - 3]) <=
            getValueOfLetter((unsigned char)pattern[patternSize - 1])
            ) {
            return false;
        }
    }

    return true;
}

int RomanNumberConverter::generateResult(std::stack<unsigned char>*& letterStack) {
    if(letterStack->empty()) {
        return 0;
    }

    const int stackSize = (int)letterStack->size();
    int sum = 0;

    for(auto i = 0; i < stackSize; i++) {
        if(sum > this->getValueOfLetter(letterStack->top())) {
            sum = sum - getValueOfLetter(letterStack->top());
        }
        else {
            sum = sum + getValueOfLetter(letterStack->top());
        }
        letterStack->pop();
    }

    return sum;
}

void RomanNumberConverter::init() {
    std::fstream file = std::fstream("test.txt" , std::ios::in);
    std::string pattern;

    if(file.is_open()) {
        while(std::getline(file , pattern)) {
            std::string copyPattern;
            std::stack<unsigned char>* romanNumberStack = new std::stack<unsigned char>();
            const int patternSize = (int)pattern.size();
            for(auto i = 0; i < patternSize; i++) {
                copyPattern.push_back(pattern[i]);
            }
            std::transform(pattern.begin() , pattern.end() , pattern.begin() , [](unsigned char letter) {
                return (unsigned char)std::toupper(letter);
            });

            if(checkIsValidExpression(pattern)) {
                for(auto i = 0; i < patternSize; i++) {
                    romanNumberStack->push(pattern[i]);
                }
                int result = generateResult(romanNumberStack);
                std::cout << copyPattern << " = " << result << std::endl;
            } else {
                std::cout << copyPattern << " = error" << std::endl;
            }
            delete romanNumberStack;
        }

    }else {
        std::cout << "Something went wrong. Please check the file" << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    RomanNumberConverter* program = new RomanNumberConverter();
    program->init();
    return 0;
}*/

/*#include <iostream>
#include <list>

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
        ~Position();
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
    ~BinaryTree();
    int size() const;
    bool isEmpty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
};

template <typename E> BinaryTree<E>::Node::Node() {
    leftChild = nullptr;
    rightChild = nullptr;
    parent = nullptr;
}

template <typename E> BinaryTree<E>::Position::Position(Node* u) {
    this->v = v;
}

template <typename E> BinaryTree<E>::Position::~Position() {
    delete v;
}

template <typename E> const E& BinaryTree<E>::Position::operator*() const {
    return this->v->element;
}

template <typename E> Position BinaryTree<E>::Position::left() const {
    return Position(this->v->leftChild);
}

template <typename E> Position BinaryTree<E>::Position::right() const {
    return Position(this->v->rightChild);
}

template <typename E> Position BinaryTree<E>::Position::parent() const {
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

template <typename E> BinaryTree<E>::~BinaryTree() {
    
}

template <typename E> int BinaryTree<E>::size() const {
    return this->entries;
}

template <typename E> bool BinaryTree<E>::isEmpty() const {
    return this->entries == 0;
}

*/

/*#include <iostream>
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
}*/


/*#include <iostream>
#include <chrono>
#include <thread>

void run(int x) {
    while(x --> 0) {
        std::cout << "Threads: " << x << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main(int argc, char const *argv[]) {
    std::thread t1(run , 10);
    if(t1.joinable()) {
        t1.detach();
    }
    std::cout << "After" << std::endl;
    return 0;
}*/

/*#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

int myAccount = 0;

void addMoney() {
    m.lock();
    myAccount++;
    m.unlock();
}

int main(int argc, char const *argv[]) {
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout << myAccount << std::endl;
    return 0;
}*/

/*#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex m;

void increaseCounter() {
    for(auto i = 0; i < 1000; i++) {
        if(m.try_lock()) {
            counter++;
            m.unlock();
        }
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(increaseCounter);
    std::thread t2(increaseCounter);

    t1.join();
    t2.join();

    std::cout << counter << std::endl;
    return 0;
}*/

/*#include <iostream>
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
}*/

/*#include <iostream>
#include <list>

template <typename E , typename C> class PriorityQueue {
private:
        std::list<E>* tempList;
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
    this->tempList = new std::list<E>();
}

template <typename E , typename C> PriorityQueue<E , C>::~PriorityQueue() {
    while(!this->isEmpty()) {
        this->removeMin();
    }

    delete tempList;
}

template <typename E , typename C> int PriorityQueue<E , C>::size() const { return (int)this->tempList->size(); }
template <typename E , typename C> bool PriorityQueue<E , C>::isEmpty() const { return this->tempList->empty(); }

template <typename E , typename C> void PriorityQueue<E , C>::insert(const E& element) {
    std::list<E>::iterator ptr = this->tempList->begin();

    while(ptr != this->tempList->end() && !this->isLess(element , *ptr)) ++ptr;
    this->tempList->insert(ptr , element);
}

template <typename E , typename C> const E& PriorityQueue<E , C>::min() const { return this->tempList->front(); }

template <typename E , typename C> void PriorityQueue<E , C>::removeMin() {
    if(this->isEmpty()) return;

    this->tempList->pop_front();
}*/


/*#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[]) {
    std::fstream file = std::fstream("test.txt" , std::ios::in);
    std::string line;
    if(file.is_open()) {
        while(std::getline(file , line)) {
            std::istringstream parsedLine;
            parsedLine.str(line);

            std::string* delims = new std::string[3];
            std::string word;
            int i = 0;
            while(std::getline(parsedLine , word , ',')) {
                delims[i++] = word;
            }

            std::cout << delims[0] << " * " << delims[1] << " * " << delims[2] << " * " << std::endl;
        }
    }
    return 0;
}*/

/*#include <iostream>
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
}*/

/*#include <iostream>
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
    bool isRoot(const Position& p);
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
    return pos(2 * idx(p));
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::right(const Position& p) {
    return pos(2 * idx(p) + 1);
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::parent(const Position& p) {
    return pos((int)(idx(p) / 2));
}

template <typename E> bool CompleteBinaryTree::hasLeft(const Position& p) const {
    return 2 * idx(p) <= size();
}

template <typename E> bool CompleteBinaryTree<E>::hasRight(const Position& p) const {
    return 2 * idx(p) + 1 <= size();
}

template <typename E> bool CompleteBinaryTree<E>::isRoot(const Position& p) const {
    return idx(p) == 1;
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::root() {
    return pos(1);
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::last() {
    return pos(size());
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
    *p = element;
}

template <typename E , typename C> class HeapPriorityQueue {
private:
    CompleteBinaryTree<E> T;
    C isLess;

private:
    typedef typename CompleteBinaryTree<E>::Position Position;

public:
    int size() const;
    bool isEmpty() const;
    void insert(const E& element);
    const E& min() const;
    void removeMin();
};

template <typename E , typename C> int HeapPriorityQueue<E , C>::size() const {
    return this->T.size();
}

template <typename E , typename C> bool HeapPriorityQueue<E , C>::isEmpty() const {
    return this->T.size() == 0;
}

template <typename E , typename C> const E& HeapPriorityQueue<E , C>::min() const {
    return *(this->T.root());
}

template <typename E , typename C> void HeapPriorityQueue<E , C>::insert(const E& element) {
    this->T.addLast(element);
    Position v = T.last();

    while(!T.isRoot(v)) {
        Position u = T.parent(v);
        if(!isLess(v , u)) break;
        swap(v , u);
        v = u;
    }
}

template <typename E , typename C> void HeapPriorityQueue<E , C>::removeMin() {
    if(T.size() == 1) {
        T.removeLast();
    }
    else {
        T.swap(T.root() , T.last());
        T.removeLast();
        Position u = T.root();

        while(T.hasLeft(u)) {
            Position v = T.left(u);
            if(T.hasRight(u) && isLess(*(T.right()) , *v)) {
                v = T.right();
            }
            if(isLess(*v , *u)) {
                T.swap(u , v);
                u = v;
            }
            else {
                break;
            }
        }
    }
}*/

/*#include <iostream>
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
    bool isEmpty() const;
    Position left(const Position& p);
    Position right(const Position& p);
    Position parent(const Position& p);
    bool hasLeft(const Position& p) const;
    bool hasRight(const Position& p) const;
    bool isRoot(const Position& p) const;
    bool root();
    bool last();
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

template <typename E> int CompleteBinaryTree<E>::size() const { return this->V.size() - 1; }
template <typename E> bool CompleteBinaryTree<E>::isEmpty() const { return this->size() == 0; }

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::left(const Position& p) {
    return this->pos(2 * this->idx(p));
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::right(const Position& p) {
    return this->pos(2 * this->idx(p) + 1);
}

template <typename E> typename CompleteBinaryTree<E>::Position CompleteBinaryTree<E>::parent(const Position& p) {
    return this->pos(this->idx(p) / 2);
}

template <typename E> bool CompleteBinaryTree<E>::hasLeft(const Position& p) const {
    return 2 * this->idx(p) <= this->size();
}

template <typename E> bool CompleteBinaryTree<E>::hasRight(const Position& p) const {
    return 2 * this->idx(p) + 1 <= this->size();
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
}*/

/*#include <iostream>
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
}*/

/*#include <iostream>
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
}*/