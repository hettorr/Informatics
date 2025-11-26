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

void del_front(TLinkOne*& head, TLinkOne*& tail,int &dat) {
	if (head == NULL) return;
	if (head == tail) {
	    dat = head -> data;
		delete head;
		head = tail = NULL;
		return;
	}
	TLinkOne* temp = head;
	dat = head -> data;
	head = head->address;
	delete temp;

}

void del_back(TLinkOne*& head, TLinkOne*& tail) {
	if (head == NULL) return;
	if (head == tail) {
		delete head;
		head = tail = NULL;
		return ;
	}
	TLinkOne* cur = head;
	while (cur->address != tail) {
		cur = cur->address;
	}
	TLinkOne* temp = tail;
	cur->address = NULL;
	tail = cur;
	delete temp;
}

void out_queue(TLinkOne*head){
    while(head != NULL){
        cout << head -> data<<" ";
        head = head -> address;
    }
    cout <<"\n";
}

int sub(TLinkOne*&head, TLinkOne*&tail, int N){
    int dat;
    TLinkOne*cur = head;
    if(N == 1){
        del_front(head,tail,dat);
        return dat;
    }
    for(int i = 0;i < N-2;i++){
        cur = cur -> address;
    }
    TLinkOne*temp = cur -> address;
    dat = temp -> data;
    cur -> address = temp -> address;
    delete temp;
    return dat;
}

int main() {
    int N,dat,temp;
    TLinkOne*head = NULL;
    TLinkOne*tail = NULL;
    cin >> N;
    for(int j = 0; j < N;j++){
        cin >> temp;
        add_back_L1_A2(head,tail,temp);
    }
    cin >> N;
    add_front_L1_A2(head,tail,sub(head,tail,N));
    out_queue(head);
    return 0;
}