#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void addToEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void addToFront(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAfter(Node* current, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
}

void insertIntoList(Node*& head, Node*& tail, int value) {
    if (head == NULL || value <= head->data) {
        addToFront(head, tail, value);
        return;
    }
    if (value >= tail->data) {
        addToEnd(head, tail, value);
        return;
    }
    
    Node* current = head;
    while (current != NULL && current->next != NULL && current->next->data <= value) {
        current = current->next;
    }
    insertAfter(current, value);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void clearList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, m, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        insertIntoList(head, tail, temp);
    }
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        insertIntoList(head, tail, temp);
    }
    
    printList(head);
    clearList(head);
    return 0;
}