#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Rib{
	int v, u;
	long long weight;
	bool operator>(const Rib& other) const {
        return weight > other.weight;
    }
};

bool comp(const Rib &A, const Rib &B){
	return A.weight < B.weight;
}

struct MSpT{
	int size;
	long long sum_weight;
	vector<pair<int,int>> ribs;
};

class SPrim{
private:
	int q_vert;
	vector<vector<Rib>> ribs;
	vector<int> used;
	
	void dfs(int v, int par){
		used[v] = true;
		for (Rib rib : ribs[v])
			if (rib.u != par && used[rib.u] == false)
				dfs(rib.u, v);
	}
	
	bool is_connected(){
		for (int i = 0; i < q_vert; ++i)
			used[i] = false;
		dfs(0, 0);
		for (int i = 0; i < q_vert; ++i)
			if(used[i] == false)
				return false;
		return true;
	}
	
public:
	SPrim(): q_vert(0){}
	SPrim(int q_vert): q_vert(q_vert){
		ribs.resize(q_vert);
		used.resize(q_vert);
	}
	
	void input_graf(){
		for (int v = 0, weight_vu; v < q_vert; ++v)
			for (int u = 0; u < q_vert; ++u){
				cin >> weight_vu;
				if (weight_vu != 0)
					ribs[v].push_back({v, u, weight_vu});
			}
	}
	
	void calc_MSpT(MSpT &tree){
		if (is_connected() == false){
			tree = {-1, -1, {}};
			return;
		}
		tree = {0, 0, {}};
		
		for (int i = 0; i < q_vert; ++i)
			used[i] = false;
		
		priority_queue<Rib, vector<Rib>, greater<Rib>> Q;
		Q.push({0, 0, 0});
		while(Q.empty() == false){
			auto [v, u, weight] = Q.top(); Q.pop();
			
			if (used[u] == false){
				used[u] = true;
			
				tree.sum_weight += weight;
				++tree.size;
				tree.ribs.push_back({v,u});
			
				for (Rib rib : ribs[u])
					if (used[rib.u] == false)
						Q.push(rib);
			}
		}
		
		--tree.size;
		tree.ribs.erase(tree.ribs.begin());
	}	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int q_vert; cin >> q_vert;
	SPrim prim(q_vert); prim.input_graf();
	
	MSpT min_spann_tree;
	prim.calc_MSpT(min_spann_tree);
	
	if (min_spann_tree.size == -1)
		cout << "-1\n";
	else {
		cout << min_spann_tree.sum_weight << '\n';
		for (pair<int,int> rib : min_spann_tree.ribs)
			cout << rib.first + 1 << ' ' << rib.second + 1 << '\n';
	}
	
	return 0;
}

