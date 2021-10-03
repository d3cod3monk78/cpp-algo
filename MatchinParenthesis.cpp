// Pattern Matching Algorithm
#include <iostream>
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
}