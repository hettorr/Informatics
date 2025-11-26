#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cost;
    int city;
    int tank;
    bool operator>(const Node& other) const {
        return cost > other.cost;
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
    vector<vector<int>> dist(N, vector<int>(2, INT_MAX));
    dist[0][0] = 0;
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 0, 0});
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        if (cur.cost > dist[cur.city][cur.tank]) continue;
        if (cur.city == N-1) {
            return cur.cost;
        }
        
        for (int v = 0; v < N; v++) {
            if (cur.city != v && graph[cur.city][v] > 0) {
                int price = prices[cur.city];
                
                if (cur.tank == 1) {
                    if (cur.cost < dist[v][0]) {
                        dist[v][0] = cur.cost;
                        pq.push({cur.cost, v, 0});
                    }
                    if (cur.cost + price < dist[v][1]) {
                        dist[v][1] = cur.cost + price;
                        pq.push({cur.cost + price, v, 1});
                    }
                }
                else {
                    if (cur.cost + price < dist[v][0]) {
                        dist[v][0] = cur.cost + price;
                        pq.push({cur.cost + price, v, 0});
                    }
                    if (cur.cost + 2 * price < dist[v][1]) {
                        dist[v][1] = cur.cost + 2 * price;
                        pq.push({cur.cost + 2 * price, v, 1});
                    }
                }
            }
        }
    }
    
    int result = min(dist[N-1][0], dist[N-1][1]);
    return result == INT_MAX ? -1 : result;
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