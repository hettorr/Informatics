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
    Tnode*parrent = NULL;
    Tnode*cur = root; 
    while(cur != NULL){
        parrent = cur;
        if(cur -> data == temp -> data){
            delete temp;
            return;
        }
        else if(cur -> data < temp -> data) cur = cur -> right;
        else cur = cur -> left;
    }
    if(parrent -> data < temp -> data){
        parrent -> right = temp;
        return;
    }
    parrent -> left = temp;
    return;
}

void count(Tnode*root,int &c){
    
    if(root == NULL)return;
    count(root -> left,c);
    c++;
    count(root -> right,c);
    return ;
    
}

int main()
{
    Tnode*root= NULL;
    int N ,c = 0;
    cin>>N;
    while(N != 0){
        
        add_leaf(root,N);
        cin>>N;
    }
    count(root,c);
    cout << c;
    return 0;
}