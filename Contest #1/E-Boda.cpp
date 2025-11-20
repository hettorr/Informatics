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

void del_front(TLinkOne*& head, TLinkOne*& tail) {
	if (head == NULL) return;
	if (head == tail) {
		delete head;
		head = tail = NULL;
		return;
	}
	TLinkOne* temp = head;
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

void kill(TLinkOne*&head, TLinkOne*&tail, int N){
    TLinkOne*cur = head;
    if(N == 1){
        del_front(head,tail);
        return;
    }
    for(int i = 0;i < N-2;i++){
        cur = cur -> address;
    }
    TLinkOne*temp = cur -> address;
    cur -> address = temp -> address;
    delete temp;
}

void insert(TLinkOne*&head, TLinkOne*&tail, int c, int N){
    TLinkOne*cur = head;
    if(c == 1){
        add_front_L1_A2(head,tail,N);
        return;
    }
    for(int i = 0;i < c-2;i++){
       cur = cur -> address;
    }
    TLinkOne*temp = new TLinkOne;
    temp -> data = N;
    temp -> address = cur -> address;
    cur -> address = temp;
}

int main() {
    int N,c,temp;
    TLinkOne*head = NULL;
    TLinkOne*tail = NULL;
    cin >> N;
    for(int j = 0; j < N;j++){
        cin >> temp;
        add_back_L1_A2(head,tail,temp);
    }
    cin >> N;
    kill(head,tail,N);
    cin >> c >>N;
    insert(head,tail,c,N);
    out_queue(head);
    return 0;
}