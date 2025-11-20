#include <iostream>
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

bool push(Queue& q, long long n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    
    if (q.tail == NULL) {
        q.head = q.tail = newNode;
    } else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
    q.count++;
    return true;
}

bool pop(Queue& q, long long& result) {
    if (q.head == NULL) {
        return false;
    }
    
    result = q.head->data;
    Node* temp = q.head;
    q.head = q.head->next;
    
    if (q.head == NULL) {
        q.tail = NULL;
    }
    
    delete temp;
    q.count--;
    return true;
}

bool front(Queue& q, long long& result) {
    if (q.head == NULL) {
        return false;
    }
    result = q.head->data;
    return true;
}

int size(Queue& q) {
    return q.count;
}

void clear(Queue& q) {
    while (q.head != NULL) {
        Node* temp = q.head;
        q.head = q.head->next;
        delete temp;
    }
    q.tail = NULL;
    q.count = 0;
}

int main() {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.count = 0;
    string command;
    long long value;
    bool running = true;
    
    while (running && cin >> command) {
        if (command == "push") {
            cin >> value;
            push(q, value);
            cout << "ok\n";
        }
        else if (command == "pop") {
            if (pop(q, value)) {
                cout << value << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (command == "front") {
            if (front(q, value)) {
                cout << value << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (command == "size") {
            cout << size(q) << '\n';
        }
        else if (command == "clear") {
            clear(q);
            cout << "ok\n";
        }
        else if (command == "exit") {
            cout << "bye\n";
            running = false;
        }
    }
    return 0;
}