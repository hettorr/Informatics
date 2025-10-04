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

void leaves(Tnode*root){
    if(root -> left == NULL && root -> right == NULL){
        cout << root -> data<<" ";
        return;
    }
    if(root-> left!= NULL)leaves(root -> left);
    if(root-> right!= NULL)leaves(root -> right);
    
}

int main()
{
    Tnode*root= NULL;
    
    int N,h =1 ;
    cin>>N; 
    while(N != 0){
        add_leaf(root,N);
        cin>>N;
    }
    leaves(root);
    return 0;
}