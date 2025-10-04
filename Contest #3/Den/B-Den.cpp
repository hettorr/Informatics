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

int countElements(TNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int count = 0;
    TNode* current = root;
    TNode* pre = NULL;
    
    while (current != NULL) {
        if (current->left == NULL) {
            count++;
            current = current->right;
        }
        else {
            pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            else {
                pre->right = NULL;
                count++;
                current = current->right;
            }
        }
    }
    
    return count;
}

int main() {
    TNode* root = NULL;
    int N;
    
    cin >> N;
    while (N != 0) {
        root = insert(root, N);
        cin >> N;
    }

    cout << countElements(root) << "\n";
    return 0;
}