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

void removeValue(Node*& head, Node*& tail, int value) {
    Node* current = head;
    Node* prev = NULL;
    
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                Node* temp = head;
                head = head->next;
                delete temp;
                current = head;
            }
            else {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                current = prev->next;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
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
    int N, P, value;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> value;
        addToEnd(head, tail, value);
    }
    cin >> P;
    
    removeValue(head, tail, P);
    printList(head);
    clearList(head);
    return 0;
}