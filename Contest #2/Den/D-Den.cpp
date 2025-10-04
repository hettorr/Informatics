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

void compressList(Node* head) {
    if (head == NULL) {
        return;
    }
    
    Node* current = head;
    while (current != NULL) {
        if (current->data != 0) {
            head->data = current->data;
            head = head->next;
        }
        current = current->next;
    }
    while (head != NULL) {
        head->data = 0;
        head = head->next;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
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
    
    string line;
    getline(cin, line);
    stringstream ss(line);
    int number;
    
    while (ss >> number) {
        addToEnd(head, tail, number);
    }
    
    compressList(head);
    printList(head);
    
    clearList(head);
    return 0;
}