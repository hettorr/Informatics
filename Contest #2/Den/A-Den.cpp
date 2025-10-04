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

bool removeFront(Node*& head, Node*& tail, int& value) {
    if (head == NULL) {
        return false;
    }
    
    value = head->data;
    Node* temp = head;
    
    if (head == tail) {
        head = tail = NULL;
    }
    else {
        head = head->next;
    }
    
    delete temp;
    return true;
}

int main() {
    Node* arturHead = NULL;
    Node* arturTail = NULL;
    Node* igorHead = NULL;
    Node* igorTail = NULL;
    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        addToEnd(arturHead, arturTail, card);
    }
    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        addToEnd(igorHead, igorTail, card);
    }
    
    int moves = 0;
    while (moves < 1000000) {
        moves++;
        
        int arturCard, igorCard;
        removeFront(arturHead, arturTail, arturCard);
        removeFront(igorHead, igorTail, igorCard);
        bool arturWins = false;
        bool igorWins = false;
        
        if (arturCard == 0 && igorCard == 9) {
            arturWins = true;
        }
        else if (arturCard == 9 && igorCard == 0) {
            igorWins = true;
        }
        else if (arturCard > igorCard) {
            arturWins = true;
        }
        else {
            igorWins = true;
        }
        
        if (arturWins) {
            addToEnd(arturHead, arturTail, arturCard);
            addToEnd(arturHead, arturTail, igorCard);
        }
        else if (igorWins) {
            addToEnd(igorHead, igorTail, arturCard);
            addToEnd(igorHead, igorTail, igorCard);
        }
        if (arturHead == NULL) {
            cout << "Igor " << moves << "\n";
            return 0;
        }
        if (igorHead == NULL) {
            cout << "Artur " << moves << "\n";
            return 0;
        }
    }
    
    cout << "Botva" << "\n";
    while (arturHead != NULL) {
        int temp;
        removeFront(arturHead, arturTail, temp);
    }
    while (igorHead != NULL) {
        int temp;
        removeFront(igorHead, igorTail, temp);
    }
    
    return 0;
}