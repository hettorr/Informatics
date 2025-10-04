#include <bits/stdc++.h>
using namespace std;

struct TNode {
    int data;
    TNode* left;
    TNode* right;
};

TNode* createNode(int value) {
    TNode* newNode = new TNode;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TNode* insert(TNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    TNode* current = root;
    TNode* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        }
        else if (value > current->data) {
            current = current->right;
        }
        else {
            return root;
        }
    }
    
    if (value < parent->data) {
        parent->left = createNode(value);
    }
    else {
        parent->right = createNode(value);
    }
    
    return root;
}

int findSecondMax(TNode* root) {
    TNode* current = root;
    TNode* prev = NULL;
    
    while (current->right != NULL) {
        prev = current;
        current = current->right;
    }
    
    if (current->left != NULL) {
        current = current->left;
        while (current->right != NULL) {
            current = current->right;
        }
        return current->data;
    }
    else {
        return prev->data;
    }
}

int main() {
    TNode* root = NULL;
    int N;
    
    cin >> N;
    while (N != 0) {
        root = insert(root, N);
        cin >> N;
    }

    cout << findSecondMax(root) << "\n";
    return 0;
}