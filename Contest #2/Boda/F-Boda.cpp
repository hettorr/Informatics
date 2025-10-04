#include <bits/stdc++.h>
using namespace std;

struct TLinkOne{
    int data;
    TLinkOne*address;
};


void add_back_L1_A2(TLinkOne*&head,TLinkOne*&tail,int N){
    TLinkOne*temp = new TLinkOne;
    temp -> data = N;
    temp -> address = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail -> address = temp;
    tail = temp;
    
}

void add_front_L1_A2(TLinkOne*&head,TLinkOne*&tail,int N){
    TLinkOne*temp = new TLinkOne;
    temp -> data = N;
    temp -> address = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    temp -> address = head;
    head = temp;
    
}

void out_queue(TLinkOne*head){
    while(head != NULL){
        cout << head -> data<<" ";
        head = head -> address;
    }
    cout <<"\n";
}

void h_insert(TLinkOne*&cur, int N){
    TLinkOne*temp = new TLinkOne;
    temp -> data = N;
    temp -> address = cur -> address;
    cur -> address = temp;
}

void insert_into_queue(TLinkOne*&head, TLinkOne*&tail, int N){
    if(head == NULL || N <= head->data){
        add_front_L1_A2(head,tail,N);
        return;
    }
    if(N >= tail->data){
        add_back_L1_A2(head,tail,N);
        return;
    }
    TLinkOne*cur = head;
    while(cur != NULL && cur->address != NULL && cur -> address -> data <= N){
        cur = cur->address;
    }
    h_insert(cur,N);
    
}

int main() {
    int N,temp;
    TLinkOne*head = NULL;
    TLinkOne*tail = NULL;
    for(int i = 0;i< 2;i++){
        cin >> N;
        for(int j = 0; j < N;j++){
            cin >> temp;
            insert_into_queue(head,tail,temp);
        }
    }
    out_queue(head);
    return 0;
}