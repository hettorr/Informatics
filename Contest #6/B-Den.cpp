#include <bits/stdc++.h>
using namespace std;

struct Node {
    int dist;
    int v;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void readPrices(int N, vector<int>& prices) {
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
}

void readRoads(int M, vector<vector<int>>& graph) {
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

int dijkstra(int N, vector<int>& prices, vector<vector<int>>& graph) {
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.dist <= dist[cur.v]) {
            for (int v = 0; v < N; v++) {
                if (cur.v != v && graph[cur.v][v] > 0) {
                    int nd = dist[cur.v] + prices[cur.v];
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }
    }

    return dist[N-1] == INT_MAX ? -1 : dist[N-1];
}

int main() {
    int N;
    cin >> N;
    vector<int> prices(N);
    readPrices(N, prices);
    
    int M;
    cin >> M; 
    vector<vector<int>> graph(N, vector<int>(N, 0));
    readRoads(M, graph);
    cout << dijkstra(N, prices, graph) << "\n";
    return 0;
}