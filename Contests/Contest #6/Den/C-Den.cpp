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
        
        if (cur.tank == 0) {
            int new_cost = cur.cost + prices[cur.city];
            if (new_cost < dist[cur.city][0]) {
                dist[cur.city][0] = new_cost;
                pq.push({new_cost, cur.city, 0});
            }
        }
        
        int new_cost2 = cur.cost + prices[cur.city] * 2;
        if (new_cost2 < dist[cur.city][1]) {
            dist[cur.city][1] = new_cost2;
            pq.push({new_cost2, cur.city, 1});
        }
        
        if (cur.tank == 1) {
            if (cur.cost < dist[cur.city][0]) {
                dist[cur.city][0] = cur.cost;
                pq.push({cur.cost, cur.city, 0});
            }
        }
        
        for (int v = 0; v < N; v++) {
            if (cur.city != v && graph[cur.city][v] > 0) {
                if (cur.tank == 1) {
                    if (cur.cost < dist[v][1]) {
                        dist[v][1] = cur.cost;
                        pq.push({cur.cost, v, 1});
                    }
                }
                
                int travel_cost = cur.cost + prices[cur.city];
                if (travel_cost < dist[v][0]) {
                    dist[v][0] = travel_cost;
                    pq.push({travel_cost, v, 0});
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