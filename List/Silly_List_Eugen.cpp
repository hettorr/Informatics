#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

struct Node{
	int val;
	Node *next;
	
	Node(): val(0), next(nullptr){};
	Node(int val): val(val), next(nullptr){};
	Node(int val, Node *next): val(val), next(next){};
};

class SList{
private:
	int len;
	Node *root, *last;
	
public:
	SList(): len(0), root(nullptr){}
	SList(int len): len(len), root(nullptr){}
	
	friend istream &operator >>(istream &input, SList &list);
	friend ostream &operator <<(ostream &output, SList &list);
	friend const SList operator +(SList &A, SList &B);
	friend const SList merge(SList &A, SList &B);
	
	bool empty(){
		return root == nullptr;
	}
	
	Node *operator[](int ind){
		if (ind >= len)
			throw runtime_error("Index out of range");
		
		Node *it = root;
		for (int i = 0; i < ind; ++i)
			it = it->next;
		
		return it;
	}
	
	Node *get_last(){
		return last;
	}
	
	Node *find(int val){
		Node *it = root;
		while (it != nullptr && it->val != val)
			it = it->next;
		return it;
	}
	
	int count(int val){
		int cnt = 0;
		Node *it = root;
		while (it != nullptr){
			if (val == it->val)
				++cnt;
			it = it->next;
		}
		return cnt;
	}
	
	void delete_val(int val){
		Node *it = root, *prev_it = nullptr;
		while (it != nullptr)
			if (it->val == val){
				if (prev_it != nullptr)
					prev_it->next = it->next;
				else
					root = it->next;
				Node *temp = it;
				it = it->next;
				delete temp;
				--len;
			}
			else {
				prev_it = it;
				it = it->next;
			}
		last = prev_it;
	}
	
	void delete_ind(int ind){
		if (ind >= len || ind < 0)
			throw runtime_error("Index out of range!");
		
		if (ind == 0){
			Node *temp = root;
			root = root->next;
			delete temp;
			--len;
			return;
		}
		
		Node *it = root;
		for (int i = 1; i < ind; ++i, it = it->next);
		
		Node *temp = it->next;
		it->next = temp->next;
		delete temp;
		if (ind == len-1)
			last = it;
		--len;
	}
	Node *delete_ind_NMR(int ind){
		if (ind >= len || ind < 0)
			throw runtime_error("Index out of range!");
		
		if (ind == 0){
			Node *temp = root;
			root = root->next;
			--len;
			return temp;
		}
		
		Node *it = root;
		for (int i = 1; i < ind; ++i, it = it->next);
		
		Node *temp = it->next;
		it->next = temp->next;
		if (ind == len-1)
			last = it;
		--len;
		return temp;
	}
	
	void insert(int ind, int val){
		if (ind > len || ind < 0)
			throw runtime_error("Index out of range!");
		
		if (ind == 0){
			root = new Node(val, root);
			++len;
			return;
		}
		
		Node *it = root;
		for (int i = 1; i < ind; ++i, it = it->next);
		
		Node *temp = new Node(val, it->next);
		it->next = temp;
		if (ind == len)
			last = temp;
		++len;
	}
	
	void shift_to_start(int ind){
		if (ind >= len || ind < 0)
			throw runtime_error("Index out of range!");
		
		if (ind == 0)
			return;
		
		Node *it = root;
		for (int i = 1; i < ind; ++i, it = it->next);
		
		Node *temp = it->next;
		it->next = temp->next;
		temp->next = root;
		root = temp;
		if (ind == len-1)
			last = it;
	}
	
	void append(int val){
		++len;		
		if (root == nullptr){
			last = root = new Node(val);
			return;
		}
		
		last->next = new Node(val);
		last = last->next;
	}
	void append(Node *node){
		node->next = nullptr;
		++len;
		
		if (root == nullptr){
			last = root = node;
			return;
		}
		
		last->next = node;
		last = last->next;
	}
};

istream &operator >>(istream &input, SList &list){
	list.root = new Node();
	Node *it = list.root;
	input >> it->val;
	for (int i = 0, val; i < list.len-1; ++i){
		input >> val;
		Node *temp = it;
		it = new Node(val);
		temp->next = it;
	}
	list.last = it;
		
	return input;
}
ostream &operator <<(ostream &output, SList &list){
	Node *it = list.root;
	for (int i = 0; i < list.len; ++i, it = it->next)
		output << it->val << ' ';
		
	return output;
}

const SList operator +(SList &A, SList &B){
	SList res;
	
	Node *it_A = A.root, *it_B = B.root;
	while (it_A != nullptr && it_B != nullptr){
		res.append(it_A->val + it_B->val);
		it_A = it_A->next;
		it_B = it_B->next;
	}
	while (it_A != nullptr){
		res.append(it_A->val);
		it_A = it_A->next;
	}
	while (it_B != nullptr){
		res.append(it_B->val);
		it_B = it_B->next;
	}
	
	return res;
}

const SList merge(SList &A, SList &B){
	SList res;
	
	Node *it_A = A.root, *it_B = B.root;
	while (it_A != nullptr && it_B != nullptr){
		if (it_A->val <= it_B->val){
			res.append(it_A->val);
			it_A = it_A->next;
		}
		else {
			res.append(it_B->val);
			it_B = it_B->next;
		}
	}
	while (it_A != nullptr){
		res.append(it_A->val);
		it_A = it_A->next;
	}
	while (it_B != nullptr){
		res.append(it_B->val);
		it_B = it_B->next;
	}
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int len_A; cin >> len_A;
	SList A(len_A); cin >> A;

	int len_B; cin >> len_B;
	SList B(len_B); cin >> B;
	
	SList C = merge(A, B);
	
	cout << C << '\n';
	
	return 0;
}

