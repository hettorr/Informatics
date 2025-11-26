#include <bits/stdc++.h>
using namespace std; 
struct Tnode{
    int data, amo;
    Tnode *left,*right;
};

void add_leaf(Tnode*&root,int N){
    Tnode*temp = new Tnode;
    temp -> data = N;
    temp -> left = temp -> right = NULL;
    temp -> amo = 1;
    if(root == NULL){
        root = temp;
        return;
    }
    Tnode*parent = NULL;
    Tnode*cur = root; 
    while(cur != NULL){
        parent = cur;
        if(cur -> data == temp -> data){
            cur -> amo ++;
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

void inorder(Tnode*root){
    if(root == NULL)return;
    inorder(root -> left);
    cout << root -> data<<" " << root -> amo<<"\n";
    inorder(root -> right);
    
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
    inorder(root);
    return 0;
}