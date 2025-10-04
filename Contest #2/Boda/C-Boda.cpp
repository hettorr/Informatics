#include <bits/stdc++.h>
using namespace std;

struct Tstack{
    int data;
    Tstack*address;
};


void push(Tstack *&top, int N){
    Tstack*temp = new Tstack;
    temp -> data = N;
    temp -> address = top;
    top = temp;
    
}

bool pop(Tstack*&top, int &dat ){
    if(top == NULL)return false;
    dat = top -> data;
    Tstack*temp = top;
    top = top -> address;
    delete temp;
    return true;
}

void do_math(Tstack*&top, char t){
    Tstack*pre_top = new Tstack;
    if(top!= NULL && top -> address != NULL)pre_top = top -> address;
    
    if(t == '+'){
        int N;
        pop(top,N);
        pre_top -> data += N; 
        return;
    }
    if(t == '-'){
        int N;
        pop(top,N);
        pre_top -> data -= N; 
        return;
    }
    if(t == '*'){
        int N;
        pop(top,N);
        pre_top -> data *= N; 
        return;
    }
    int N = t - '0';
    push(top,N);
}

int main() {
    char temp;
    int N;
    Tstack*top = NULL;
    while(cin >> temp){
        do_math(top,temp);
    }
    cout << top -> data<<"\n";
    return 0;
}