#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 1e9;

class SGraf{
private:
	int q_vert;
	vector<vector<bool>> ribs;
	vector<int> dist;
	
	void bfs(int start){
		queue<int> Q;
		dist[start] = 0;
		Q.push(start);
		while(Q.empty() == false){
			int v = Q.front(); Q.pop();
			for (int i = 0; i < q_vert; ++i)
				if (ribs[v][i] && dist[i] == INF){
					dist[i] = dist[v] + 1;
					Q.push(i);
				}
		}
	}
	
public:
	SGraf():q_vert(0){}
	SGraf(const int &q_vert):q_vert(q_vert){
		ribs.assign(q_vert, vector<bool>(q_vert));
		dist.assign(q_vert, INF);
	}
	
	void input_adj_matrix(istream &input){
		bool is_connected;
		for (int i = 0; i < q_vert; ++i)
			for (int j = 0; j < q_vert; ++j){
				input >> is_connected;
				ribs[i][j] = is_connected;
			}
	}
	
	int calc_dist(const int &v, const int &u){
		for (int i = 0; i < q_vert; ++i)
			dist[i] = INF;
		
		bfs(v);
		
		return dist[u];
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int q_vert, v, u; cin >> q_vert >> v >> u;
	--v; --u;
	
	SGraf graf(q_vert); graf.input_adj_matrix(cin);
	
	int dist = graf.calc_dist(v, u);
	cout << (dist == INF ? 0 : dist) << '\n';
	
	return 0;
}