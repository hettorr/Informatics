#include <bits/stdc++.h>
using namespace std;

const int Nmax = 305;

struct edge {
    int to, weight;
};

struct Node {
    int vertex, parent, weight;
    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

void read_matrix(int N, vector<vector<edge>>& graph) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int weight;
            cin >> weight;
            if (weight > 0 && i != j) {
                graph[i].push_back({j, weight});
            }
        }
    }
}

int prim(int N, vector<vector<edge>>& graph, vector<pair<int, int>>& mst) {
    vector<bool> visited(N + 1, false);
    vector<int> min_edge(N + 1, INT_MAX);
    vector<int> parent(N + 1, -1);
    
    min_edge[1] = 0;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, -1, 0});
    
    int total_weight = 0;
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        if (visited[cur.vertex]) continue;
        
        visited[cur.vertex] = true;
        total_weight += cur.weight;
        
        if (cur.parent != -1) {
            mst.push_back({min(cur.vertex, cur.parent), max(cur.vertex, cur.parent)});
        }
        
        for (const edge& e : graph[cur.vertex]) {
            if (!visited[e.to] && e.weight < min_edge[e.to]) {
                min_edge[e.to] = e.weight;
                parent[e.to] = cur.vertex;
                pq.push({e.to, cur.vertex, e.weight});
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) return -1;
    }
    
    return total_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<vector<edge>> graph(N + 1);
    read_matrix(N, graph);
    
    vector<pair<int, int>> mst;
    int total_weight = prim(N, graph, mst);
    
    if (total_weight == -1) {
        cout << -1 << "\n";
    }
    else {
        cout << total_weight << "\n";
        for (const auto& edge : mst) {
            cout << edge.first << " " << edge.second << "\n";
        }
    }
    
    return 0;
}