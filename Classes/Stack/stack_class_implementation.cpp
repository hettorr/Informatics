#include<bits/stdc++.h>
using namespace std;

template <typename DataType>
class Stack_node{
public:
    DataType data;
    Stack_node<DataType>* addr;
};
template <typename DataType>
class Stack{
private:
    Stack_node<DataType> *top = nullptr;
    int size = 0;
public:
    void push(DataType data);
    void pop();
    DataType back_st();
    bool empty_(){
        return (top == nullptr);
    }
    int size_(){
        return size;
    }
    void clear_();
    ~Stack();

};
template <typename DataType>
void Stack<DataType>::push(DataType data){
    Stack_node<DataType>* st = new Stack_node<DataType>;
    st->data = data;
    st->addr = top;
    size++;
    top = st;
}
template <typename DataType>
void Stack<DataType>::pop(){
    if (top == nullptr)
        return;
    Stack_node<DataType>* new_top = top->addr;
    delete top;
    top = new_top;
    size--;
}
template <typename DataType>
DataType Stack<DataType>::back_st(){
    return top->data;
}
template<typename DataType>
void Stack<DataType>::clear_(){
    while (top != nullptr)
        pop();
    size = 0;
}
template <typename DataType>
Stack<DataType>::~Stack() {
    clear_();
}


int main(){
    Stack<int> basic_st;
    string command;
    bool flag = true;
    while (flag){
        cin >> command;
        if (command == "push"){
            int n;
            cin >> n;
            basic_st.push(n);
            cout << "ok\n";
        }
        else if (command == "pop"){
            if (basic_st.empty_()) cout << "error";
            else{
                cout << basic_st.back_st();
                basic_st.pop();
            }
            cout << "\n";
        }
        else if (command == "back"){
            if (basic_st.empty_()) cout << "error";
            else cout << basic_st.back_st();
            cout << "\n";
        }
        else if (command == "size")
            cout << basic_st.size_() << "\n";
        else if (command == "clear"){
            basic_st.clear_();
            cout << "ok\n";
        }
        else if (command == "exit"){
            basic_st.clear_();
            cout << "bye";
            flag = false;
        }
    }
    return 0;
}

