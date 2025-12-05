#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    double prob;
};

struct Node {
    double prob;
    int v;
    bool operator>(const Node& other) const {
        return prob > other.prob;
    }
};

void readGraph(int roads, vector<vector<Edge>>& graph) {
    for (int i = 0; i < roads; i++) {
        int from, to, p;
        cin >> from >> to >> p;
        from--; to--;
        double prob = p / 100.0;
        graph[from].push_back({to, prob});
        graph[to].push_back({from, prob});
    }
}

double dijkstra(int buildings, int start, int finish, vector<vector<Edge>>& graph) {
    vector<double> dist(buildings, 1.0);
    dist[start] = 0.0;
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0.0, start});
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        if (cur.prob <= dist[cur.v]) {
            if (cur.v == finish) {
                return cur.prob;
            }
            
            for (const Edge& e : graph[cur.v]) {
                double new_prob = 1.0 - (1.0 - cur.prob) * (1.0 - e.prob);
                
                if (new_prob < dist[e.to]) {
                    dist[e.to] = new_prob;
                    pq.push({new_prob, e.to});
                }
            }
        }
    }
    
    return dist[finish];
}

int main() {
    int buildings, roads, start, finish;
    cin >> buildings >> roads >> start >> finish;
    start--; finish--;
    vector<vector<Edge>> graph(buildings);
    readGraph(roads, graph);
    
    double result = dijkstra(buildings, start, finish, graph);
    cout << fixed << setprecision(6) << result << "\n";
    return 0;
}