#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Node {
    long long data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
    int count;
};

void push(Queue& q, long long n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    
    if (q.tail == NULL) {
        q.head = newNode;
        q.tail = newNode;
    }
    else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
    q.count++;
    cout << "ok\n";
}

void pop(Queue& q) {
    if (q.head == NULL) {
        cout << "error\n";
        return;
    }
    Node* temp = q.head;
    cout << q.head->data << '\n';
    q.head = q.head->next;
    if (q.head == NULL) {
        q.tail = NULL;
    }
    delete temp;
    q.count--;
}

void front(Queue& q) {
    if (q.head == NULL) {
        cout << "error\n";
        return;
    }
    cout << q.head->data << '\n';
}

void size(Queue& q) {
    cout << q.count << '\n';
}

void clear(Queue& q) {
    while (q.head != NULL) {
        Node* temp = q.head;
        q.head = q.head->next;
        delete temp;
    }
    q.tail = NULL;
    q.count = 0;
    cout << "ok\n";
}

void exit() {
    cout << "bye\n";
}

int main() {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.count = 0;
    string command;
    bool running = true;
    
    while (running && cin >> command) {
        if (command == "push") {
            long long n;
            cin >> n;
            push(q, n);
        }
        else if (command == "pop") {
            pop(q);
        }
        else if (command == "front") {
            front(q);
        }
        else if (command == "size") {
            size(q);
        }
        else if (command == "clear") {
            clear(q);
        }
        else if (command == "exit") {
            exit();
            running = false;
        }
    }
    return 0;
}