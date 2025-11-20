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

bool back(Tstack*top, int &dat){
    if(top == NULL)return false;
    dat = top->data;
    return true;
}

int size(Tstack*top){
    int res = 0;
    while(top!=NULL){
        top = top -> address;
        res++;
    }
    return res;
    
}

void clear(Tstack*&top){
    Tstack*temp = top;
    while(top != NULL){
        temp = top;
        top = top -> address;
        delete temp;
    }
    
}

int main() {
    string com;
    int N,dat;
    Tstack*top = NULL;
    bool flag = true;
    while(flag){
        cin >> com;
        if(com == "push"){
            cin >> N;
            push(top,N);
            cout << "ok"<<"\n";
        }
        else if(com == "pop"){
            if(!pop(top,dat)) cout << "error" <<"\n";
            else cout << dat<<"\n";
        }
        else if(com == "back"){
            if(!back(top,dat)) cout << "error"<<"\n";
            else cout << dat <<"\n";
        }
        else if(com == "size"){
            cout << size(top)<<"\n";
        }
        else if(com == "clear"){
            clear(top);
            cout << "ok"<<"\n";
        }
        else if(com == "exit"){
            flag = false;
            cout << "bye"<<"\n";
        }
    }
    return 0;
}