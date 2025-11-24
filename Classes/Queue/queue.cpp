#include <iostream>
#include <string>
using namespace std;

struct Node {
    long long data;
    Node* next;
    Node* prev;
};

struct Deque {
    Node* head;
    Node* tail;
    int count;
};

bool push_front(Deque& d, long long n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->prev = NULL;
    newNode->next = d.head;
    
    if (d.head == NULL) {
        d.head = d.tail = newNode;
    }
    else {
        d.head->prev = newNode;
        d.head = newNode;
    }
    d.count++;
    return true;
}

bool push_back(Deque& d, long long n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = d.tail;
    
    if (d.tail == NULL) {
        d.head = d.tail = newNode;
    }
    else {
        d.tail->next = newNode;
        d.tail = newNode;
    }
    d.count++;
    return true;
}

bool pop_front(Deque& d, long long& result) {
    if (d.head == NULL) {
        return false;
    }
    
    result = d.head->data;
    Node* temp = d.head;
    
    if (d.head == d.tail) {
        d.head = d.tail = NULL;
    }
    else {
        d.head = d.head->next;
        d.head->prev = NULL;
    }
    
    delete temp;
    d.count--;
    return true;
}

bool pop_back(Deque& d, long long& result) {
    if (d.tail == NULL) {
        return false;
    }
    
    result = d.tail->data;
    Node* temp = d.tail;
    
    if (d.head == d.tail) {
        d.head = d.tail = NULL;
    }
    else {
        d.tail = d.tail->prev;
        d.tail->next = NULL;
    }
    
    delete temp;
    d.count--;
    return true;
}

bool front(Deque& d, long long& result) {
    if (d.head == NULL) {
        return false;
    }
    result = d.head->data;
    return true;
}

bool back(Deque& d, long long& result) {
    if (d.tail == NULL) {
        return false;
    }
    result = d.tail->data;
    return true;
}

int size(Deque& d) {
    return d.count;
}

void clear(Deque& d) {
    while (d.head != NULL) {
        Node* temp = d.head;
        d.head = d.head->next;
        delete temp;
    }
    d.tail = NULL;
    d.count = 0;
}

int main() {
    Deque d;
    d.head = NULL;
    d.tail = NULL;
    d.count = 0;
    string command;
    long long value;
    bool running = true;
    
    while (running && cin >> command) {
        if (command == "push_front") {
            cin >> value;
            push_front(d, value);
            cout << "ok\n";
        }
        else if (command == "push_back") {
            cin >> value;
            push_back(d, value);
            cout << "ok\n";
        }
        else if (command == "pop_front") {
            if (pop_front(d, value)) {
                cout << value << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (command == "pop_back") {
            if (pop_back(d, value)) {
                cout << value << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (command == "front") {
            if (front(d, value)) {
                cout << value << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (command == "back") {
            if (back(d, value)) {
                cout << value << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (command == "size") {
            cout << size(d) << '\n';
        }
        else if (command == "clear") {
            clear(d);
            cout << "ok\n";
        }
        else if (command == "exit") {
            cout << "bye\n";
            running = false;
        }
    }
    return 0;
}
