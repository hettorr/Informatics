#include <bits/stdc++.h>
using namespace std;

struct TLinkOne {
	int data;
	TLinkOne*address;
};


void push_back(TLinkOne*& head, int dat) {
	TLinkOne* temp = new TLinkOne;
	temp->data = dat;
	temp->address = NULL;

	if (head == NULL) {
		head = temp;
		return;
	}
	TLinkOne* cur = head;
	while (cur->address != NULL) {
		cur = cur->address;
	}
	cur->address = temp;
}

void push_front(TLinkOne*& head, int dat) {
	TLinkOne* temp = new TLinkOne;
	temp->data = dat;
	temp->address = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}

	temp->address = head;
	head = temp;
}

void out_queue(TLinkOne*head){
    while(head != NULL){
        cout << head -> data<<" ";
        head = head -> address;
    }
    cout <<"\n";
}

int main() {
    int N_P,N_Q,num,temp;
    TLinkOne*head = NULL;
    TLinkOne*cur = NULL;
    bool flag = true;
    cin >> N_P;
    for(int i = 0; i<= N_P;i++){
        cin >> num;
        push_back(head,num);
    }
    cur = head;
    cin>> N_Q;
    if(N_Q <= N_P){
        for(int i = 0;i <= N_Q;i++){
            cin >> num;
            cur -> data += num;
            cur = cur -> address;
        }
    }
    else{
        for(int i = 0;i <= N_P;i++){
            cin >> num;
            cur -> data += num;
            cur = cur -> address;
        }
        for(int i = 0;i < N_Q-N_P;i++){
            cin >> num;
            push_back(head,num);
        }
        
    }
    out_queue(head);
    
    
    
    return 0;
}