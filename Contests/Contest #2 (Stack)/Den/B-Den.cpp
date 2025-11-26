#include <bits/stdc++.h>
using namespace std;

struct Node {
    char bracket;
    Node* next;
};

void push(Node*& top, char bracket) {
    Node* newNode = new Node;
    newNode->bracket = bracket;
    newNode->next = top;
    top = newNode;
}

bool pop(Node*& top, char& bracket) {
    if (top == NULL) {
        return false;
    }
    
    bracket = top->bracket;
    Node* temp = top;
    top = top->next;
    delete temp;
    return true;
}

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    }
    else if (open == '[' && close == ']') {
        return true;
    }
    else if (open == '{' && close == '}') {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    Node* stackTop = NULL;
    string sequence;
    getline(cin, sequence);
    
    for (int i = 0; i < sequence.length(); i++) {
        char current = sequence[i];
        
        if (current == '(' || current == '[' || current == '{') {
            push(stackTop, current);
        }
        else if (current == ')' || current == ']' || current == '}') {
            char topBracket;
            if (!pop(stackTop, topBracket)) {
                cout << "NO" << "\n";
                return 0;
            }
            
            if (!isMatching(topBracket, current)) {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    
    if (stackTop == NULL) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

    while (stackTop != NULL) {
        char temp;
        pop(stackTop, temp);
    }
    return 0;
}