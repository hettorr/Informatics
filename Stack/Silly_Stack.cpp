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

class SStack{
private:
	int size;
	Node *top_node;
	
public:
	SStack(): size(0), top_node(nullptr){};
	
	void push(int val){
		top_node = new Node(val, top_node);
		++size;
	}
	
	bool empty(){
		return top_node == nullptr;
	}
	
	int top(){
		if (empty())
			throw runtime_error("Stack is empty!");
		
		return top_node->val;
	}
	int pop(){
		if (empty())
			throw runtime_error("Stack is empty!");
		
		int return_val = top();
		
		Node *temp = top_node;
		top_node = top_node->next;
		delete temp;
		--size;
		
		return return_val;
	}
	
	int get_size(){
		return size;
	}
	
	void clear(){
		while (top_node != nullptr){
			Node *temp = top_node;
			top_node = top_node->next;
			delete temp;
		}
		size = 0;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	SStack Pol_arifm;
	
	char mem; int a, b;
	while (cin >> mem){
		if (isdigit(mem))
			Pol_arifm.push(mem - '0');
		else {
			b = Pol_arifm.pop(); a = Pol_arifm.pop();
			switch (mem){
			case '+':
				Pol_arifm.push(a + b);
				break;
			case '-':
				Pol_arifm.push(a - b);
				break;
			case '*':
				Pol_arifm.push(a * b);
				break;
			}
		}
	}
	
	cout << Pol_arifm.pop() << '\n';
	
	return 0;
}
