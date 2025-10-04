#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long data;
    Node* next;
};

void push(Node*& top, long long value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

bool pop(Node*& top, long long& value) {
    if (top == NULL) {
        return false;
    }
    value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return true;
}

int main() {
    Node* stackTop = NULL;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            long long b, a;
            if (!pop(stackTop, b) || !pop(stackTop, a)) {
                cout << "error" << "\n";
                return 1;
            }
            
            long long result;
            if (token == "+") {
                result = a + b;
            }
            else if (token == "-") {
                result = a - b;
            }
            else if (token == "*") {
                result = a * b;
            }
            
            push(stackTop, result);
        }
        else {
            long long num = stoi(token);
            push(stackTop, num);
        }
    }
    
    long long finalResult;
    if (pop(stackTop, finalResult)) {
        cout << finalResult << "\n";
    }
    else {
        cout << "error" << "\n";
    }
    
    while (stackTop != NULL) {
        long long temp;
        pop(stackTop, temp);
    }
    
    return 0;
}