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

int getHeight(TNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TNode* root) {
    if (root == NULL) {
        return true;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    TNode* root = NULL;
    int N;
    cin >> N;
    
    while (N != 0) {
        root = insert(root, N);
        cin >> N;
    }

    if (isBalanced(root)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}