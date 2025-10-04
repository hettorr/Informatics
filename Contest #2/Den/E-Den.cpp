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
    Node* current = NULL;
    int n_p, n_q, num;
    cin >> n_p;
    for (int i = 0; i <= n_p; i++) {
        cin >> num;
        addToEnd(head, tail, num);
    }
    
    current = head;
    cin >> n_q;
    if (n_q <= n_p) {
        for (int i = 0; i <= n_q; i++) {
            cin >> num;
            current->data += num;
            current = current->next;
        }
    }
    else {
        for (int i = 0; i <= n_p; i++) {
            cin >> num;
            current->data += num;
            current = current->next;
        }
        for (int i = 0; i < n_q - n_p; i++) {
            cin >> num;
            addToEnd(head, tail, num);
        }
    }
    
    printList(head);
    clearList(head);
    
    return 0;
}