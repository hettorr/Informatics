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

bool compare(Tnode*root){
    int h = 0,h2 = 0;
    if(abs(find_height(root -> left,h) - find_height(root -> right,h2)) > 1) return false;
    if (root->left != NULL && !compare(root->left)) return false;
    if (root->right != NULL && !compare(root->right)) return false;
    return true;
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
    if(compare(root))cout << "YES\n";
    else cout << "NO\n";
    return 0;
}