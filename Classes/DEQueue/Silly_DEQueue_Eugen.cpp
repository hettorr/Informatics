#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

struct DENode{
	int val;
	DENode *prev, *next;
	
	DENode(): val(0), prev(nullptr), next(nullptr){}
	DENode(int val): val(val), prev(nullptr), next(nullptr){}
	DENode(int val, DENode *prev): val(val), prev(prev), next(nullptr){}
	DENode(int val, DENode *prev, DENode *next): val(val), prev(prev), next(next){}
};

class SDEQueue{
private: 
	int size;
	DENode *back_node, *front_node;
	
public:
	SDEQueue(): size(0), back_node(nullptr), front_node(nullptr){}
	
	bool empty(){
		return back_node == nullptr;
	}
	
	void push_front(int val){
		if (empty()){
			front_node = new DENode(val);
			back_node = front_node;
		}
		else {
			front_node = new DENode(val, nullptr, front_node);
			front_node->next->prev = front_node;
		}
		++size;
	}
	void push_back(int val){
		if (empty()){
			back_node = new DENode(val);
			front_node = back_node;
		}
		else {
			back_node = new DENode(val, back_node);
			back_node->prev->next = back_node;
		}
		++size;
	}
	
	int front(){
		if (empty())
			throw runtime_error("Dequeue is empty!");
		
		return front_node->val;
	}
	int pop_front(){
		if (empty())
			throw runtime_error("Dequeue is empty!");
		
		int return_val = front();
		
		DENode *temp = front_node;
		front_node = front_node->next;
		delete temp;
		--size;
		
		if (size == 0)
			back_node = nullptr;
		else
 			front_node->prev = nullptr;
		
		return return_val;
	}
	
	int back(){
		if (empty())
			throw runtime_error("Dequeue is empty!");
		
		return back_node->val;
	}
	int pop_back(){
		if (empty())
			throw runtime_error("Dequeue is empty!");
		
		int return_val = back();
		
		DENode *temp = back_node;
		back_node = back_node->prev;
		delete temp;
		--size;
		
		if (size == 0)
			front_node = nullptr;
		else
 			back_node->next = nullptr;
		
		return return_val;
	}
	
	int get_size(){
		return size;
	}
	
	void clear(){
		while (front_node != nullptr){
			DENode *temp = front_node;
			front_node = front_node->next;
			delete temp;
		}
		back_node = nullptr;
		size = 0;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	SDEQueue s;
	
	string command; int val;
	cin >> command;
	while (command != "exit"){
		if (command == "push_front"){
			cin >> val;
			s.push_front(val);
			cout << "ok\n";
		}
		if (command == "push_back"){
			cin >> val;
			s.push_back(val);
			cout << "ok\n";
		}
		if (command == "pop_front"){
			try{
				cout << s.pop_front() << '\n';
			}
			catch(runtime_error error){
				if(strcmp(error.what(), "Dequeue is empty!") == 0)
					cout << "error\n";
			}
		}
		if (command == "pop_back"){
			try{
				cout << s.pop_back() << '\n';
			}
			catch(runtime_error error){
				if(strcmp(error.what(), "Dequeue is empty!") == 0)
					cout << "error\n";
			}
		}
		if (command == "front"){
			try{
				cout << s.front() << '\n';
			}
			catch(runtime_error error){
				if(strcmp(error.what(), "Dequeue is empty!") == 0)
					cout << "error\n";
			}
		}
		if (command == "back"){
			try{
				cout << s.back() << '\n';
			}
			catch(runtime_error error){
				if(strcmp(error.what(), "Dequeue is empty!") == 0)
					cout << "error\n";
			}
		}
		if (command == "size"){
			cout << s.get_size() << '\n';
		}
		if (command == "clear"){
			s.clear();
			cout << "ok\n";
		}
		
		cin >> command;
	}
	cout << "bye\n";
	
	return 0;
}
