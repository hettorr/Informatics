#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Node {
    long long data;
    Node* next;
};

struct Stack {
    Node* top;
    int count;
};

void initStack(Stack& data) {
    data.top = NULL;
    data.count = 0;
}

void push(Stack& data, long long n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = data.top;
    data.top = newNode;
    data.count++;
    cout << "ok\n";
}

void pop(Stack& data) {
    if (data.top == NULL) {
        cout << "error\n";
        return;
    }
    Node* temp = data.top;
    cout << data.top->data << '\n';
    data.top = data.top->next;
    delete temp;
    data.count--;
}

void back(Stack& data) {
    if (data.top == NULL) {
        cout << "error\n";
        return;
    }
    cout << data.top->data << '\n';
}

void size(Stack& data) {
    cout << data.count << '\n';
}

void clear(Stack& data) {
    while (data.top != NULL) {
        Node* temp = data.top;
        data.top = data.top->next;
        delete temp;
    }
    data.count = 0;
    cout << "ok\n";
}

void exit() {
    cout << "bye\n";
}

int main() {
    Stack data;
    initStack(data);
    string command;
    bool running = true;
    
    while (running && cin >> command) {
        if (command == "push") {
            long long n;
            cin >> n;
            push(data, n);
        }
        else if (command == "pop") {
            pop(data);
        }
        else if (command == "back") {
            back(data);
        }
        else if (command == "size") {
            size(data);
        }
        else if (command == "clear") {
            clear(data);
        }
        else if (command == "exit") {
            exit();
            running = false;
        }
    }
    return 0;
}