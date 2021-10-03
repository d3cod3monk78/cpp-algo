#include <iostream>
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
}