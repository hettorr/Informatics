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

class SQueue{
private:
	int size;
	Node *back_node, *front_node;

public:
	SQueue(): size(0), back_node(nullptr), front_node(nullptr){}
	
	bool empty(){
		return back_node == nullptr;
	}
	
	void push(int val){
		if (empty()){
			back_node = new Node(val);
			front_node = back_node;
		}
		else {
			Node *temp = back_node;
			back_node = new Node(val);
			temp->next = back_node;
		}
		++size;
	}
	
	int front(){
		if (empty())
			throw runtime_error("Queue is empty!");
		
		return front_node->val;
	}
	int pop(){
		if (empty())
			throw runtime_error("Queue is empty!");
		
		int return_val = front();
		
		Node *temp = front_node;
		front_node = front_node->next;
		delete temp;
		--size;
		
		if (size == 0)
			back_node = nullptr;
		
		return return_val;
	}
	
	int get_size(){
		return size;
	}
	
	void clear(){
		while (front_node != nullptr){
			Node *temp = front_node;
			front_node = front_node->next;
			delete temp;
		}
		back_node = nullptr;
		size = 0;
	}
};

void input(int len, SQueue &q){
	for (int i = 0, val; i < len; ++i){
		cin >> val;
		q.push(val);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	SQueue Artur, Igor;
	input(5, Artur); input(5, Igor);
	
	int cnt = 0;
	while ((cnt <= 1000) && !Artur.empty() && !Igor.empty()){
		if ((Artur.front() > Igor.front() && !(Artur.front() == 9 && Igor.front() == 0)) || (Artur.front() == 0 && Igor.front() == 9)){
			Artur.push(Artur.pop());
			Artur.push(Igor.pop());
		}
		else if ((Artur.front() < Igor.front() && !(Artur.front() == 0 && Igor.front() == 9)) || (Artur.front() == 9 && Igor.front() == 0)){
			Igor.push(Artur.pop());
			Igor.push(Igor.pop());
		}
		++cnt;
		
	}
	
	if (cnt > 1000){
		cout << "Botva\n";
		return 0;
	}
	if (Artur.empty())
		cout << "Igor " << cnt << '\n';
	else
 		cout << "Artur " << cnt << '\n';
		
	return 0;
}
