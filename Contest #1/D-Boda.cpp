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

void kill(TLinkOne*&cur){
    TLinkOne*temp = cur -> address;
    cur -> address = temp -> address;
    delete temp;
}

void delete_the_prey(TLinkOne*&head, TLinkOne*&tail, int prey){
    while(head != NULL && head->data == prey){
        TLinkOne*temp = head;
        head = head -> address;
        delete temp;
    }
    if(head == NULL){ 
        tail = NULL;
        return;
    }
    TLinkOne*cur = head;
    while(cur != NULL && cur->address != NULL){
        if(cur->address->data == prey){
            TLinkOne*temp = cur->address;
            cur->address = temp->address;
            if(temp == tail) tail = cur; 
            delete temp;
        } else {
            cur = cur->address;
        }
    }
}

int main() {
    int N,temp,prey;
    TLinkOne*head = NULL;
    TLinkOne*tail = NULL;
    cin >> N;
    for(int j = 0; j < N;j++){
        cin >> temp;
        add_back_L1_A2(head,tail,temp);
    }
    cin >> prey;
    delete_the_prey(head,tail,prey);
    out_queue(head);
    return 0;
}