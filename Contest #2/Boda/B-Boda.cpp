#include <bits/stdc++.h>
using namespace std;

struct TLinkOne {
	int data;
	TLinkOne*address;
};

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

void pop_front(TLinkOne*& head) {
	if (head == NULL) return;
	if (head ->address == NULL) {
		delete head;
		head = NULL;
		return;
	}

	TLinkOne* temp = head;
	head = head->address;
	delete temp;
	return;
}

int code_bra(char bra){
    if(bra == '(') return 1;
	if(bra == ')') return -1;
	if(bra == '[') return 2;
	if(bra == ']') return -2;
	if(bra == '{') return 3;
	return -3;
}

void new_bra(TLinkOne*&head,int N){
    if(head == NULL || head -> data + N != 0 || (head -> data + N == 0 && N > 0)){
	    push_front(head,N);
	    return;
	}
	pop_front(head);
	
}

int main() {
	char bra;
	int N;
	TLinkOne*head = NULL;
	while(cin >> bra){
	    N = code_bra(bra);
	    new_bra(head,N);
	}
	if(head == NULL) cout << "YES"<<"\n";
	else cout << "NO"<<"\n";
	
	return 0;
}