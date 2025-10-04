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

int find_height(Tnode*root,int height){
    if(root == NULL){

        return height-1;
    }
    return max(find_height(root -> left, height+1),find_height(root -> right, height+1));
    
    

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
    cout << find_height(root,h)<<"\n";
    return 0;
}