#include <bits/stdc++.h>
using namespace std;

struct TLinkOne{
    int data;
    TLinkOne*address;
};


void add_L1_A2(TLinkOne*&head,TLinkOne*&tail,int N){
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
    if(N == 0){
        add_L1_A2(head,tail,N);
        return;
    }
    if((tail!= NULL && tail -> data != 0)|| head == NULL){
        add_L1_A2(head,tail,N);
        return;
    }
    TLinkOne*cur = head;
    if(head -> data == 0){
        add_front_L1_A2(head,tail,N);
    }
    while(cur != NULL && cur->address != NULL && cur -> address -> data!= 0){
        cur = cur->address;
    }
    h_insert(cur,N);
    
}

int main() {
    int N;
    TLinkOne*head = NULL;
    TLinkOne*tail = NULL;
    while(cin >> N){
        insert_into_queue(head,tail,N);
    }
    out_queue(head);
    return 0;
}