#include <iostream>

using namespace std;

struct Node{
    int val, cnt;
    Node *left_son, *right_son;
    
    Node(): val(0), cnt(0), left_son(nullptr), right_son(nullptr){}
    Node(int val): val(val), cnt(0), left_son(nullptr), right_son(nullptr){}
    Node(int val, int cnt): val(val), cnt(cnt), left_son(nullptr), right_son(nullptr){}
    Node(int val, int cnt, Node *left): val(val), cnt(cnt), left_son(left), right_son(nullptr){}
    Node(int val, int cnt, Node *left, Node *right): val(val), cnt(cnt), left_son(left), right_son(right){}
};

class SSearchTree{
private:
    Node *root;
    int size;
    
    void output_inorder(Node *subtree_root, ostream &output){
        if (subtree_root == nullptr)
            return;
        
        output_inorder(subtree_root->left_son, output);
        output << subtree_root->val << ' ';
        output_inorder(subtree_root->right_son, output);
    }
    void output_inorder_with_cnts(Node *subtree_root, ostream &output){
        if (subtree_root == nullptr)
            return;
        
        output_inorder_with_cnts(subtree_root->left_son, output);
        output << subtree_root->val << ' ' << subtree_root->cnt << '\n';
        output_inorder_with_cnts(subtree_root->right_son, output);
    }
    
    int get_subtree_height(Node *subtree_root){
		if (subtree_root == nullptr)
			return 0;
		
		return max(get_subtree_height(subtree_root->left_son), get_subtree_height(subtree_root->right_son)) + 1;
	}
	
	void clear_subtree(Node *subtree_root){
        if (subtree_root == nullptr)
            return;
        
        if (subtree_root->left_son != nullptr)
            clear_subtree(subtree_root->left_son);
        if (subtree_root->right_son != nullptr)
            clear_subtree(subtree_root->right_son);
        delete subtree_root;
        subtree_root = nullptr;
        --size;
    }
    
    void output_subtree_leaves(Node *subtree_root, ostream &output){
		if (subtree_root == nullptr)
			return;
		if (subtree_root->left_son == nullptr && subtree_root->right_son == nullptr)
			cout << subtree_root->val << ' ';
		
		output_subtree_leaves(subtree_root->left_son, output);
		output_subtree_leaves(subtree_root->right_son, output);
	}
	void output_subtree_branches(Node *subtree_root, ostream &output){
		if (subtree_root == nullptr)
			return;
		
		output_subtree_branches(subtree_root->left_son, output);
		if (subtree_root->left_son != nullptr && subtree_root->right_son != nullptr)
			cout << subtree_root->val << ' ';
		output_subtree_branches(subtree_root->right_son, output);
	}
	void output_subtree_sticks(Node *subtree_root, ostream &output){
		if (subtree_root == nullptr)
			return;
		
		output_subtree_sticks(subtree_root->left_son, output);
		if ((subtree_root->left_son != nullptr) ^ (subtree_root->right_son != nullptr))
			cout << subtree_root->val << ' ';
		output_subtree_sticks(subtree_root->right_son, output);
	}
	
	pair<bool, int> check_subtree_balance(Node* subtree_root) {
        if (subtree_root == nullptr) return {true, 0};
        
        pair<bool,int> left = check_subtree_balance(subtree_root->left_son);
        if (!left.first) return {false, 0};
        
        pair<bool,int> right = check_subtree_balance(subtree_root->right_son);
        if (!right.first) return {false, 0};
        
        bool balanced = abs(left.second - right.second) <= 1;
        int height = 1 + max(left.second, right.second);
        
        return {balanced, height};
    }

public:
    SSearchTree(): size(0), root(nullptr){}
    SSearchTree(int size): size(size), root(nullptr){}
    
    friend istream &operator >>(istream &input, SSearchTree &tree);
    friend ostream &operator <<(ostream &output, SSearchTree &tree);
    
    bool empty(){
		return root == nullptr;
	}
	
	int get_size(){
		return size;
	}
    
    void push_no_copies(int val){
        Node **leaf = &root;
        while ((*leaf) != nullptr){
            if (val < (*leaf)->val)
                leaf = &(*leaf)->left_son;
            else if (val > (*leaf)->val)
                leaf = &(*leaf)->right_son;
			else {
				++(*leaf)->cnt;
				return;
			}
        }
        *leaf = new Node(val, 1);
        ++size;
    }
    
    int second_max(){
		if (size < 2)
			throw runtime_error("Tree is too small");
		
		Node *it = root, *prev;
		while (it->right_son != nullptr){
			prev = it;
			it = it->right_son;
		}
		if (it->left_son == nullptr)
			return prev->val;
		it = it->left_son;
		while (it->right_son != nullptr)
			it = it->right_son;
		return it->val;
	}
    
    void clear(){
        clear_subtree(root);
        root = nullptr;
    }
    
    int get_tree_height(){
		return get_subtree_height(root);
	}
	
	bool check_batalnce(){
		return check_subtree_balance(root).first;
	}
    
    void input_till_zero(){
        clear();
        
        int val; cin >> val;
        while(val != 0){
            push_no_copies(val);
            cin >> val;
        }
    }
    
    void output_leaves(ostream &output){
		output_subtree_leaves(root, output);
		output << '\n';
	}
	void output_branches(ostream &output){
		output_subtree_branches(root, output);
		output << '\n';
	}
	void output_sticks(ostream &output){
		output_subtree_sticks(root, output);
		output << '\n';
	}
    
    ~SSearchTree(){
		clear();
	}
};

istream &operator >>(istream &input, SSearchTree &tree){
    int size = tree.size;
    tree.clear();
    for (int i = 0, val; i < size; ++i){
        cin >> val; 
        tree.push_no_copies(val);
    }
    return input;
}
ostream &operator <<(ostream &output, SSearchTree &tree){
    if (tree.root == nullptr)
        output << "Nothing to output\n";
    tree.output_inorder_with_cnts(tree.root, output);
    return output;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    SSearchTree tree; 
    
    tree.input_till_zero();
    
    cout << tree;
    
    return 0;
}
