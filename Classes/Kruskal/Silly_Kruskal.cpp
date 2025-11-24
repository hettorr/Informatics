#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rib{
	int v, u, ind;
	long long weight;
};

bool comp(const Rib &A, const Rib &B){
	return A.weight < B.weight;
}

struct MSpT{
	int size;
	long long sum_weight;
	vector<int> ribs;
};

class SKruskal{
private:
	int q_vert;
	vector<vector<Rib>> ribs;
	vector<int> subsets, used;
	
	
	int get_subset(int v){
		if (v == subsets[v])
			return v;
		return subsets[v] = get_subset(subsets[v]);
	}
	
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
	SKruskal(): q_vert(0){}
	SKruskal(int q_vert): q_vert(q_vert){
		ribs.resize(q_vert);
		subsets.resize(q_vert);
		used.resize(q_vert);
	}
	
	void input_graf(){
		int q_ribs; cin >> q_ribs;
		for (int i = 0, v, u, weight; i < q_ribs; ++i){
			cin >> v >> u >> weight; --v; --u;
			
			ribs[v].push_back({v, u, i, weight});
			ribs[u].push_back({u, v, i, weight});
		}
	}
	
	void calc_MSpT(MSpT &tree){
		if (is_connected() == false){
			tree = {-1, -1, {}};
			return;
		}
		tree = {0, 0, {}};
		
		for (int i = 0; i < q_vert; ++i)
			subsets[i] = i;
		
		vector<Rib> ribs_set;
		for (const vector<Rib> &vert : ribs)
			for (const Rib &rib : vert)
				ribs_set.push_back(rib);
		sort(ribs_set.begin(), ribs_set.end(), comp);
		
		for (Rib rib : ribs_set)
			if (get_subset(rib.v) != get_subset(rib.u)){
				subsets[get_subset(rib.v)] = get_subset(rib.u);
				tree.ribs.push_back(rib.ind);
				++tree.size;
				tree.sum_weight += rib.weight;
			}
	}	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int q_vert; cin >> q_vert;
	SKruskal kruskal(q_vert); kruskal.input_graf();
	
	MSpT min_spann_tree;
	kruskal.calc_MSpT(min_spann_tree);
	
	if (min_spann_tree.size == -1)
		cout << "-1\n";
	else {
		cout << min_spann_tree.sum_weight << '\n';
		for (int rib : min_spann_tree.ribs)
			cout << rib + 1 << '\n';
	}
	
	return 0;
}

