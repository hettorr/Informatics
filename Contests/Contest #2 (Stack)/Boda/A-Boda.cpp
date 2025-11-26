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

bool del_L1_A2(TLinkOne*&head, TLinkOne*&tail, int&dat){
    if(head == NULL)return false;
    dat = head -> data;
    if(head == tail){
        dat = tail -> data;
        delete head;
        head =tail=NULL;
        return true;
    }
    TLinkOne*temp = head;
    head = head ->address;
    delete temp;
    return true;
}

void read_cards(TLinkOne*&head_1,TLinkOne*&tail_1,TLinkOne*&head_2, TLinkOne*&tail_2){
    int N;
    for(int i = 0;i < 5;i++){
        cin >> N;
        add_L1_A2(head_1,tail_1,N);
    }
    for(int i = 0;i < 5;i++){
        cin >> N;
        add_L1_A2(head_2,tail_2,N);
    }
}

void simulate_move(TLinkOne*&head_1,TLinkOne*&tail_1,TLinkOne*&head_2, TLinkOne*&tail_2){
    int temp1, temp2;
    if(!(head_1 -> data == 9 && head_2 -> data == 0)&&((head_1 -> data > head_2 -> data) || (head_1 -> data == 0 && head_2 -> data == 9))){
        if(!del_L1_A2(head_2,tail_2,temp2))return;
        if(!del_L1_A2(head_1,tail_1,temp1))return;
        add_L1_A2(head_1,tail_1,temp1);
        add_L1_A2(head_1,tail_1,temp2);
        return;
    }
    if(!del_L1_A2(head_1,tail_1,temp1))return;
    if(!del_L1_A2(head_2,tail_2,temp2))return;
    add_L1_A2(head_2,tail_2,temp1);
    add_L1_A2(head_2,tail_2,temp2);
}

int main() {
    int N, counter = 0;
    TLinkOne*head_1 = NULL;
    TLinkOne*tail_1 = NULL;
    TLinkOne*head_2 = NULL;
    TLinkOne*tail_2 = NULL;
    read_cards(head_1,tail_1,head_2,tail_2);
    while(head_1 != NULL && head_2 != NULL){
        simulate_move(head_1,tail_1,head_2,tail_2);
        counter ++;
    }
    if(head_1 == NULL) cout<<"Igor "<<counter<<"\n";
    else cout<<"Artur "<<counter<<"\n";
    return 0;
}