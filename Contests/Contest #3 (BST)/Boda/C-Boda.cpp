#include <bits/stdc++.h>
using namespace std; 
struct Tnode{
    int data;
    Tnode *left,*right;
};

void add_leaf(Tnode*&root,int N){
    Tnode*temp = new Tnode;
    temp -> data = N;
    temp -> left = temp -> right = NULL;
    if(root == NULL){
        root = temp;
        return;
    }
    Tnode*parent = NULL;
    Tnode*cur = root; 
    while(cur != NULL){
        parent = cur;
        if(cur -> data == temp -> data){
            delete temp;
            return;
        }
        else if(cur -> data < temp -> data) cur = cur -> right;
        else cur = cur -> left;
    }
    if(parent -> data < temp -> data){
        parent -> right = temp;
        return;
    }
    parent -> left = temp;
    return;
}

int second_gratest(Tnode*root){
    Tnode*parent = NULL;
    while(root -> right != NULL){
        parent = root;
        root = root -> right;
    }
    if(root -> left != NULL){
        root = root -> left;
        while(root -> right != NULL){
            root = root -> right;
        }
        return root -> data;
    }
    return parent-> data;
    
}

int main()
{
    Tnode*root= NULL;
    
    int N;
    cin>>N; 
    while(N != 0){
        add_leaf(root,N);
        cin>>N;
    }
    cout << second_gratest(root)<<"\n";
    return 0;
}